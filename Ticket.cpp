#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class BookTicket
{
    int a, b;
    int num_seats, num_stations;

public:
    BookTicket(int x, int y)
    {
        num_seats = x;
        num_stations = y;
    }
    bool bookingTicket()
    {
        int arr[num_seats][num_stations];
        while (1)
        {
            cout << "Enter departure station: ";
            cin >> a;
            cout << "Enter destination station: ";
            cin >> b;
            --b;
            int s = 0, i, j;
            for (i = 1; i <= num_seats; ++i)
            {
                int c = 0;
                for (j = a; j <= b; ++j)
                {
                    if (arr[i][j] == 0)
                        ++c;
                }
                if (c == (b - a + 1))
                {
                    cout << "Your seat number: " << i << endl;
                    s = i;
                    break;
                }
            }
            if (s != 0)
            {
                for (i = s, j = a; j <= b; ++j)
                    arr[i][j] = 1;
            }
            if (i == num_seats + 1)
            {
                cout << "No Single seat left for whole journey !" << endl;
                cout << "Do you want cutting seats !" << endl;
                cout << "Press 1 for cutting seat and 0 to exit: ";
                int c;
                cin >> c;
                if (c == 0)
                    break;
                else
                {
                    vector<pair<int, int>> ans;
                    for (j = a; j <= b; ++j)
                    {
                        for (i = 0; i <= num_seats + 1; ++i)
                        {
                            if (arr[i][j] == 0)
                                ans.push_back({i, j});
                        }
                    }
                    if (ans.size() == (b - a + 1))
                    {
                        cout << "Your respective seats are :" << endl;
                        for (auto it : ans)
                        {
                            cout << "For station " << it.second << " to station " << (it.second + 1) << "seat number :" << it.first << endl;
                        }
                    }
                    else
                        cout << "Sorry! no cutting seat left" << endl;
                }
            }
        }
    }
};