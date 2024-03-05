#include <stdio.h>

void main()
{
    int n;
    scanf("%d", &n);
    int playlist[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &playlist[i]);
    }
    int singer_freq[n][2];
    for(int i = 0; i < n; i++)
    {
        int singer = playlist[i];
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(playlist[i] == playlist[j])
            {
                count++;
            }
        }
        singer_freq[i][0] = singer;
        singer_freq[i][1] = count;
    }
    int index;
    int high = singer_freq[0][1];
    for(int i = 0; i < n; i++)
    {
        if(singer_freq[i][1] >= high)
        {
            high = singer_freq[i][1];
        }
    }
    int fav[n];
    for(int i = 0; i < n; i++)
    {
        if(singer_freq[i][1] == high)
        {
            int duplicate = 0;
            for(int j = 0; j < n; j++)
            {
                if(fav[j] == singer_freq[i][0])
                {
                    duplicate++;
                }
            }
            if(duplicate == 0)
            {
                fav[i] = singer_freq[i][0];
            }
            else
            {
                fav[i] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", fav[i]);
    }
    printf("\n");

    int fav_count = 0;
    for(int i = 0; i < n; i++)
    {
        if(fav[i] != 0)
        {
            fav_count++;
        }
    }
    printf("%d\n", fav_count);
}