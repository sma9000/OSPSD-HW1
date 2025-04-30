#ifndef NLP_PROCESSOR_H
#define NLP_PROCESSOR_H

#include "INLPProcessor.h"
#include <string>

class NLPProcessor : public INLPProcessor {
public:
    std::string preprocessInput(const std::string& input) override;
    std::string postprocessOutput(const std::string& output) override;
};

#endif // NLP_PROCESSOR_H
