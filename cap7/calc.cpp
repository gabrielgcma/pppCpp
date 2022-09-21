/*

    Simple Calculator 

    Revision history: 
            Revised by Bjarne Stroustrup November 2013
            Revised by Bjarne Stroustrup May 2007
            Revised by Bjarne Stroustrup August 2006
            Revised by Bjarne Stroustrup August 2004
            Originally written by Bjarne Stroustrup
                    (bs@cs.tamu.edu) Spring 2004.

    This program implements a basic expression calculator.
    Input from cin; output to cout.
    The gramamar for input is:

    Statement:
        Expression 
        Print
        Quit

    Print:
        ;
    
    Quit:
        q;

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point literal

    
    Input comes from cin trough the Token_stream called ts.

*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

constexpr char number = '8';
constexpr char quit = 'x';
constexpr char print = ';';
const string prompt = "> ";
const string result = "= ";

class Token
{
public:
    char kind;     // what kind of token
    double value;  // for numbers: a value
    Token(char ch) // make a Token from a char
        : kind(ch), value(0)
    {
    }
    Token(char ch, double val) // make a Token from a char and a double
        : kind(ch), value(val)
    {
    }
};

//------------------------------------------------------------------------------

class Token_stream
{
public:
    Token_stream();        // make a Token_stream that reads from cin
    Token get();           // get a Token (get() is defined elsewhere)
    void putback(Token t); // put a Token back
    void ignore(char c);   // discard chars up to and including c
private:
    bool full;    // is there a Token in the buffer?
    Token buffer; // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    : full(false), buffer(0) // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer = t;  // copy t to buffer
    full = true; // buffer is now full
}

// c represents the kind of token
void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind){
        full = false;
        return;
    }

    full = false;

    // now search input:
    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

//------------------------------------------------------------------------------

// read chars form cin and compose a Token
Token Token_stream::get()
{
    if (full) // checks whether we have a token ready
    { 
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
        case print: 
        case quit: 
        case '(': 
        case ')': 
        case '+': 
        case '-': 
        case '*': 
        case '/':
        case '{': 
        case '}':
            return Token(ch); // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '9':
        {
            cin.putback(ch); // put digit back into the input stream
            double val;
            cin >> val;             // read a floating-point number
            return Token(number, val); // let '8' represent "a number"
        }
        default:
            error("Bad token");
            exit(1);
    }
}

//------------------------------------------------------------------------------

Token_stream ts; // provides get() and putback()

//------------------------------------------------------------------------------

double expression(); // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();

    switch (t.kind)
    {
        case '(': // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                error("')' expected");
            return d;
        } 
        case '{':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') error("'}' expected");
            return d;
        } 
        case number:           
            return t.value; // return the number's value
        case '-':  
            return - primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next token from token stream

    while (true)
    {
        switch (t.kind)
        {
            case '*':
                left *= primary();
                t = ts.get();
            case '/':
            {
                double d = primary(); 
                if (d == 0)
                    error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                int i1 = narrow_cast<int>(left);
                int i2 = narrow_cast<int>(primary());
                if (i2 == 0) error( "%: divide by zero");
                left = i1 % i2;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t); // put t back into the token stream
                return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get();   // get the next token from token stream

    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t); // put t back into the token stream
            return left;   // finally: no more + or -: return the answer
        }
    }
}

void cleanup ()
{
    ts.ignore(print);
}

void calculate()
{
    while (cin) try
    {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print)
            t = ts.get(); 
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << expression() << '\n'; 
    }
    catch (exception& e){
        cerr << e.what() << '\n';
        cleanup();
    }
}

//------------------------------------------------------------------------------

int main()
{
cout << "Welcome to our simple calculator!\n"
     << "Please enter expressions using floating-point numbers.\n"
     << "Type a valid operation and press Enter. Press x and Enter to quit.\n";
try
{   
    calculate();
    keep_window_open();
    return 0;
}
catch (runtime_error&  e)
{
    cerr << e.what() << '\n';
    keep_window_open("~~");
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open("~~");
    return 2;
}
}

//------------------------------------------------------------------------------