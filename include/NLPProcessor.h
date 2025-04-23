#ifndef NLP_PROCESSOR_H
#define NLP_PROCESSOR_H

#include <string>

class NLPProcessor {
public:
    std::string preprocessInput(const std::string& input);
    std::string postprocessOutput(const std::string& output);
};

#endif // NLP_PROCESSOR_H
