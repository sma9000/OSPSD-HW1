#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <string>

TEST(IntegrationTest, PipelineProducesResultsFile) {
    std::remove("results.csv");

    const char* python_path = std::getenv("PYTHON_BIN");
    std::string python = python_path ? python_path : "python3";
    std::string script_path = "/root/project/scripts/run_pipeline.py";

    // Run pipeline and capture log
    std::string cmd = python + " " + script_path + " > pipeline.log 2>&1";
    int ret = std::system(cmd.c_str());
    ASSERT_EQ(ret, 0) << "Pipeline execution failed. Check pipeline.log for details.";

    std::ifstream result("results.csv");
    ASSERT_TRUE(result.is_open()) << "results.csv not created.";

    std::string header;
    std::getline(result, header);
    EXPECT_EQ(header, "mail_id,Pct_spam");

    int line_count = 0;
    std::string line;
    while (std::getline(result, line)) {
        EXPECT_NE(line.find(','), std::string::npos);
        line_count++;
    }

    EXPECT_GT(line_count, 0) << "No spam scores written.";
}
