""" Python script for local testing (compatible with both Python 2 and Python 3)Disclaimer: this is a way to test your solutions, but it is NOT the real judgingsystem. The judging system behavior might be different."""from __future__ import print_functionimport subprocessimport sysUSAGE_MSG = """Usage:Linux and Mac users:  From your terminal, run    python testing_tool.py command_to_run_your_script_or_executable  Note that command_to_run_your_script_or_executable is read as a list of  arguments, so you should NOT wrap it with quotation marks.Examples:C++, after compilation:  python testing_tool.py ./my_binaryPython:  python testing_tool.py python my_code.pyJava, after compilation:  python testing_tool.py java my_main_class_nameSee https://code.google.com/codejam/resources/faq