#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

TEST(E2ETest, PipelineGeneratesSpamScores) {
    const char* apiKey = std::getenv("OPENAI_API_KEY");
    if (!apiKey) {
        GTEST_SKIP() << "OPENAI_API_KEY not set. Skipping E2E test.";
    }

    std::remove("results.csv");

    const char* python_path = std::getenv("PYTHON_BIN");
    std::string python = python_path ? python_path : "python3";
    std::string script_path = "/root/project/scripts/run_pipeline.py";
    std::string log_path = "/root/project/build/pipeline.log";

    std::string cmd = python + " " + script_path + " > " + log_path + " 2>&1";
    int ret = std::system(cmd.c_str());

    ASSERT_EQ(ret, 0) << "Pipeline execution failed. Log output:\n"
                      << ([]() {
                           std::ifstream log("/root/project/build/pipeline.log");
                           std::stringstream buffer;
                           buffer << log.rdbuf();
                           return buffer.str();
                         })();

    std::ifstream result("results.csv");
    ASSERT_TRUE(result.is_open()) << "results.csv not created.";

    std::string header;
    std::getline(result, header);
    EXPECT_EQ(header, "mail_id,Pct_spam");

    int lines = 0;
    std::string line;
    while (std::getline(result, line)) {
        EXPECT_NE(line.find(','), std::string::npos);
        lines++;
    }

    EXPECT_GT(lines, 0);
}
