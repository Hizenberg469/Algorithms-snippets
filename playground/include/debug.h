#ifndef __DEBUG__
#define __DEBUG__

/*
*   var_name: to display variable name used
*   var_value: to display variable value with variable name.
*/

#define var_name(arg) #arg


#ifdef NPRINT_VAR
    #define   var_value(arg)   ((void)0)
#else
    #define var_value(arg) cout << var_name(arg) << ": " << arg << endl;
#endif

#endif