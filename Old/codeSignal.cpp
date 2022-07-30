// add
int solution(int param1, int param2)
{
    return param1 + param2;
}

//  centuryFromYear
int solution(int year)
{
    return year % 100 == 0 ? year / 100 : (year / 100) + 1;
}

// checkPalindrome
bool solution(string inputString)
{
    string p = inputString;
    reverse(p.begin(), p.end());
    return p == inputString ? true : false;
}
