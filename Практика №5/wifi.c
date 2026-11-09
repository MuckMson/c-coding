#include <stdio.h>

int max(int a, int b){
    return a>=b ? a:b;
}

int main(){
    int rssi[24] = {-42, -55, -67, -81, -88, -79, -60, -45, -39, -52,
        -63, -74, -85, -90, -77, -58, -44, -41, -53, -66, -72, -80, -59,
        -47};
    int LEN = (sizeof(rssi)/sizeof(rssi[0]));

    int good_cnt = 0;
    int mid_cnt = 0;
    int low_cnt = 0;

    int rssi_sum = 0;

    for (int i = 0; i<LEN; i++){
        int _rssi = rssi[i];
        rssi_sum += _rssi;
        if (_rssi > -50){ good_cnt++;}
        else if(_rssi <= -50 && _rssi >= -70) {mid_cnt++;}
        else {low_cnt++;}
    }
    printf("Часов хорошего сигнала: %d\nЧасов среднего сигнала: %d\nЧасов плохого сигнала: %d\n\n",good_cnt, mid_cnt, low_cnt);
    int mean = rssi_sum/LEN;
    printf("Средний уровеень сигнала: %d\n", mean);
    int max_failure = 0;
    int failure_start = -1;
    
    for (int i = 0; i<LEN; i++){
        if (rssi[i] < -70 && failure_start == -1){
            failure_start = i;
        }
        else if(rssi[i] >= -70 && failure_start != -1){
            max_failure = max(max_failure, (i-failure_start));
            failure_start = -1;
        }
    }
    if (failure_start != -1) max_failure = max(max_failure, (24-failure_start));
    printf("Макс. длительность слабого сигнала Wi-Fi: %d ч.", max_failure);
}