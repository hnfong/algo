#pragma once

class TestCase {
  public:
    virtual int run() = 0;
    virtual const char *name() = 0;

    static int runTests();
    static TestCase* registerTest(TestCase *t);

  protected:
    int numErrors = 0;
};

#define TEST(q, msg) do { if (!(q)) { std::cerr << "Failed at " << __FILE__ << ":" << __LINE__ << " -- " << (#q) << ": " << msg << std::endl; numErrors ++; } } while (0)
