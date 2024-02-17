#include<stdio.h>

int main()
{
    float _num, _psum=0, _nsum=0;
    int _ncount=0, _pcount=0;

    do
    {
        printf("Enter Number ");
        scanf("%f", &_num);
        if(_num<0)
        {
            _nsum+=_num;
            ++_ncount;
        }
        else
        {
            _psum+=_num;
            ++_pcount;
        }
    }while(_num != 0);

    if(_ncount==0)
    {
        printf("Avg of Positive is %.2f Avg of Negetive is 0.00", _psum/(_pcount-1));
    }
    else if((_pcount-1)==0)
    {
        printf("Avg of Positive is 0.00 Avg of Negetive is %.2f", _nsum/_ncount);
    }
    else
    {
        printf("Avg of Positive is %.2f Avg of Negetive is %.2f", _psum/(_pcount-1), _nsum/_ncount);
    }
    return 0;
}

