// Fill out your copyright notice in the Description page of Project Settings.


#include "aictl.h"
#include <string>
#include <Python.h>

#include <cstdio>   // For popen(), pclose()
#include <cstring>  // For strerror()

#include <cstdlib>  // For system() function


FString Aictl::aictl(const char* venvdir, const char* pypath, const char* pydir, TArray<const char*> args) {
    // setenv("PYTHONPATH",pypath.c_str(), 1);
    FString response;

    PyObject *pFunc;
    PyObject *pArgs, *pResult;

    // system(venvdir);
    const char * devscript = R"V0G0N(
                      def main(resultdir, command, *argv): 
                           return 'Hello'
)V0G0N";
    const char *pyscript =  R"V0G0N(
                    from sentence_transformers import SentenceTransformer, util
                    from TTS.api import TTS
                    import torch, hashlib, csv, random, sys
                    sentences = []
                    def compare_sentences(sentence1, sentence2):
                       embeddings = SentenceTransformer('all-MiniLM-L6-v2').encode([sentence1, sentence2])
                       cosine_scores = util.pytorch_cos_sim(embeddings[0], embeddings[1])
                       return cosine_scores.item()
                    def load_sentences(tsv_path):
                        with open(tsv_path, newline='') as tsv_file:
                            reader = csv.reader(tsv_file, delimiter='\t')
                            for row in reader:
                                sentences.append((row[1],row[3]))

                    def get_random_sentence():
                        return random.choice(sentences)

                    def produce_sound(text):
                            sha256_hash = hashlib.sha256(text.encode()).hexdigest()[:32]
                            file_path=f"static/{sha256_hash}.wav"
                            TTS(model_name="tts_models/ja/kokoro/tacotron2-DDC", progress_bar=False).tts.tts_to_file(text, file_path=file_path)
                            return file_path

                    def main(resultdir, command, *argv): 
                        # Assign the arguments to variables
                        string1 = resultdir
                        string2 = command

                        results = ""
                        
                        # Comparing two strings for similarity. CLI will print comparison of arg 3 and 4
                        if command == "c":
                            results = (compare_sentences(argv[0], argv[1]))

                        # The request wants to generate a new sentence
                        elif command == "g":
                            results = (get_random_sentence())
                        
                        # Prints the path to the sound file generated from input text
                        elif command == "s":
                            results = (produce_sound(argv[0]))

                        else:
                           # print (resultdir, command )
                            print("Command ' "+command+" 'is not found")
                            results = "Null"
                        return str(results)
                      
                      ";
   )V0G0N"; 
    Py_Initialize();
   // pName = PyUnicode_DecodeFSDefault(pydir);
   // pModule = PyImport_Import(pName);
   // Py_DECREF(pName);

   // if (pModule != NULL) {
        // Get the reference to the function within the Python module
        //pFunc = PyObject_GetAttrString(PyImport_AddModule("__main__"), "my_function"); //  PyObject_GetAttrString(pModule, "main")

        pFunc =PyUnicode_FromString ( devscript);
       // if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(args.Num());

            for (int i = 0; i < args.Num(); i++) {
                PyTuple_SetItem(pArgs, i, PyUnicode_FromString(args[i] ));
            }

            pResult = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pResult != NULL) {
                // Convert the Python result to a C string
                response = PyUnicode_AsUTF8(pResult);
                Py_DECREF(pResult);
            } else {
                PyErr_Print();
                // std::cerr << "Failed to execute Python function." << std::endl;
            }
     //   } 
        Py_XDECREF(pFunc);
   

    // Finalize Python interpreter
   // Py_Finalize();


    return response;
}
