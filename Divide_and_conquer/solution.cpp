#include <bits/stdc++.h>

using namespace std;

int main()
{

    // input
    int n, k;
    cin >> n >> k;
    if (k > n)
    {
        cout << -1;
    }
    else
    {
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // max
        int max = arr[0];
        for (int i = 0; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
        // sum
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        // Binary search to reduce the max partition sum as much as possible, work space shrinks with time
        int left = max, right = sum;
        int partitions[k];
        int ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2; // divide
            int partitions = 0;
            int sumOfSubarray = 0;

            for (int i = 0; i < n; i++)
            {
                sumOfSubarray += arr[i];

                if (sumOfSubarray > mid)
                {
                    partitions++;
                    sumOfSubarray = arr[i];
                }
            }
            if (partitions >= k)
                left = mid + 1;
            else
            {
                right = mid - 1;
                ans = mid;
            }
        }
        sum = 0;

        // output

        cout << "Answer : " << ans << endl
             << endl;

        cout << "Partiitons : " << endl;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > ans)
            {
                cout << endl;
                sum = arr[i];
            }

            cout << arr[i] << " ";
        }
    }
}