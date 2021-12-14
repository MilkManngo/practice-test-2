#include <iostream>
#include <cmath>
#include <iomanip>  // header needed for std::setprecision()
#include <cstdlib>              // Header with rand() and srand() functions
#include <ctime>                // Header with time() function
using namespace std;
//int main()
//{
//    srand(time(nullptr));          // Initialize pseudo-random generator with current time
//    int a = rand() % 100 + 50;  // Generate random number in range 50..149

//    return 0;
//}

//int a;
//int main()
//{


//    while(x)
//    {
//        cout << "press 3 to exit" << endl;
//        cin >> a;
//        switch(a)
//        {
//        case 1:
//        {
//            // kod
//            break;
//        }
//        case 2:
//        {
//            // kod
//            break;
//        }
//        case 3:
//        {
//            x = false;
//            break;
//        }

//        }
//    }
//}
bool x = true;
bool v = true;
double* plp;
int cas;
int a_a1 = 5, b_a1 = 1;
int *c = &a_a1;
int ala_size, smallest  = 2147483647;
double a_T1[256];
double z_T1 = 1.0, p_T1, l_T1;
int rand_size;
double array_test[2];
double array_test_2[2];
int a_2a, b_2a, c_2a, rest, rest_a, rest_b, numbers[100];
int len_3a[4], len_3b[4];
int fib(int a)
{
    if(a == 1)
    {
        return(0);
    }
    else if(a == 2)
    {
        return(1);
    }
    else
    {
        return fib(a-1) + fib(a - 2);
    }
}

int small_val(int *arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        if(arr[i] == '\0')
        {
            break;
        }
        else if(arr[i] <= smallest) // smallest jest równe max int, tylko dlatego działa
        {
            smallest = arr[i];
        }
        else{}
    }
    return smallest;
}

double* geo_sum(double* arr, double arr_size)
{

    for(int  i = 0; i < arr_size; i++)
    {
        p_T1 = p_T1 +arr[i];
    }

    for(int  i = 0; i < arr_size; i++)
    {
        z_T1 = z_T1*arr[i];
    }

    l_T1 = pow(z_T1,1.0/arr_size);
    array_test[0] = p_T1;
    array_test[1] = l_T1;

    return (array_test);
}
void non_divi(int a, int b, int c)
{
    int u = 0;

    for(int i = a; i <= b; i++)
    {
        rest = i % c;

        if(rest == '\0')
        {
          numbers[u] = 0;
        }
        else
        {
            numbers[u] = i;
            u++;
        }
    }

}

int find_largest_area(int* arr_a, int* arr_b)
{
    double y = 0.0;
    double o = 0.0;

    for(int i = 0; i <= 3; i++)
    {
        for(int r = 0; r <= 3; r++)
        {
            y = (double)(arr_a[i] * (double)arr_b[r])/2.0;

            if(y > o)
            {
                o = y;
                v = true;
            }
            else if(y == o)
            {
                v = false;
            }
            else{}
        }
    }
    if(v == true)
    {
        return(y);
    }
    else
    {
        return(0);
    }


}



int main()
{
    while(x)
    {
        cout << "Wybierz zadanie\n"
             << "1 - assg 1 - ciąg fibonaciego\n"
             << "2 - assg 2\n"
             << "3 - Test 1A\n"
             << "4 - Test 2a\n"
             << "5 - Test 3a\n";
        cin >> cas;
        switch(cas)
        {
        case 0:
        {
            x = false;
            break;
        }
        case 1:
        {
            cout << "Wybrano zad 1 - ciąg fibonaciego." << endl;
            cout << "Wybierz liczbę w ciągu." << endl;
            cin >> a_a1;
            cout << fib(a_a1);

            break;
        }
        case 2:
        {
            int ala[] = {2 ,4 ,7 ,9 ,13 ,4 , 3};
            ala_size = sizeof(ala)/sizeof(ala[0]);
            cout << ala_size << endl;
            cout << "najmniejsza liczba to: " << small_val(ala, ala_size) << endl;
            break;

        }
        case 3:
        {
            for(int i = 0; i < 256; i++)
            {
                srand(time(nullptr));          // Initialize pseudo-random generator with current time
                a_T1[i] = rand() % 16 + 1;

            }
            rand_size = sizeof(a_T1)/sizeof(a_T1[0]);
//            cout << "results: " << geo_sum(a_T1,rand_size) << endl;
            plp = geo_sum(a_T1,rand_size);
            cout << *plp << endl;
            cout << *(plp +1) << endl;
            break;
        }

        case 4:
        {
            cout << "Provide 3 numbers" << endl;
            cin >> a_2a >> b_2a >> c_2a;
            if(a_2a > b_2a)
            {
                int d_2a;
                d_2a = b_2a;
                b_2a = a_2a;
                a_2a = d_2a;
            }
            non_divi(a_2a, b_2a, c_2a);
            for(int i = 0; i < (b_2a - a_2a); i++)
            {
                if(numbers[i] == '\0')
                    break;
                cout << numbers[i] << " " << endl;
            }
            break;
        }

        case 5:
        {
            cout << "provide 4 numbers" << endl;
            cin >> len_3a[0];
            cin >> len_3a[1];
            cin >> len_3a[2];
            cin >> len_3a[3];
            cout << "\nprovide 4 numbers again" << endl;
            cin >> len_3b[0];
            cin >> len_3b[1];
            cin >> len_3b[2];
            cin >> len_3b[3];
            cout << "largest area: " << find_largest_area(len_3a, len_3b) << endl;


            break;
        }

        case 6:
        {
            break;
        }


        }
    }
}
