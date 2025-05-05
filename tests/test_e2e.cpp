#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>

TEST(E2ETest, PipelineGeneratesSpamScores) {
    const char* apiKey = std::getenv("OPENAI_API_KEY");
    if (!apiKey) {
        GTEST_SKIP() << "OPENAI_API_KEY not set. Skipping E2E test.";
    }

    std::remove("results.csv");

    // Fixed: Run Python script instead of Windows-style .exe
    int ret = std::system("python3 scripts/run_pipeline.py > /dev/null");
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

