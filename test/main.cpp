#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/TextOutputter.h>
#include <fstream>

#include <boost/regex.hpp>


#include <cstdlib>

int main(int argc, char* argv[]) {
    // Define test variables
    using namespace CppUnit;
    using namespace std;
    using namespace boost;

    TestResult controller;
    TestResultCollector result;
    controller.addListener(&result);

    TextUi::TestRunner runner;
    TestFactoryRegistry& registry = TestFactoryRegistry::getRegistry();
    Test* testToRun = registry.makeTest(); 

    if(argc == 1) { // No arguments
        runner.addTest(testToRun);
    } else {
        // Let's assume a regular expression in the first parameter
        auto tests = ((TestSuite*)testToRun)->getTests();
        regex expression(argv[1],regex::egrep);
        for_each(tests.begin(),tests.end(),
                 [&runner,expression](Test* theTest){
                    cmatch what;
                    if(regex_match(theTest->getName().c_str(),what,expression)){
                        runner.addTest(theTest);
                    }
                 });
    }

    runner.run(controller);
    
    // Write results into XML
    // ofstream xmlFileOut("cpptestresults.xml");
    // XmlOutputter xmlOut(&result, xmlFileOut);
    // xmlOut.write();
    // xmlFileOut.close();

    // And to the console
    TextOutputter textOutput(&result, std::cout);
    textOutput.write();
    
    return 0;
}

