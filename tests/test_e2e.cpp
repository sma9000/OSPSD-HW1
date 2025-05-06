#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>

TEST(E2ETest, PipelineGeneratesSpamScores) {
    const char* apiKey = std::getenv("OPENAI_API_KEY");
    if (!apiKey) {
        GTEST_SKIP() << "OPENAI_API_KEY not set. Skipping E2E test.";
    }

    std::remove("results.csv");

    // Use environment-defined Python path or fallback to python3
    const char* python_path = std::getenv("PYTHON_BIN");
    std::string python = python_path ? python_path : "python3";
    std::string cmd = python + " ../scripts/run_pipeline.py > /dev/null";
    int ret = std::system(cmd.c_str());
    ASSERT_EQ(ret, 0) << "Pipeline execution failed.";

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
