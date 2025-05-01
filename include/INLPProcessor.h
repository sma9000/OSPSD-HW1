// INLPProcessor.h
#ifndef INLP_PROCESSOR_H
#define INLP_PROCESSOR_H

#include <string>

class INLPProcessor {
public:
    virtual std::string preprocessInput(const std::string& input) = 0;
    virtual std::string postprocessOutput(const std::string& output) = 0;
    virtual ~INLPProcessor() {}
};

#endif // INLP_PROCESSOR_H