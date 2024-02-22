#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <memory.h>
// #include <string>

using namespace std;

struct LectureTime {
    int start;
    int end;
};

int LectureRoom() {
    int nCount;
    int ret = 1;
    string lecTime;
    vector<string> inCommands;
    vector<LectureTime> lecList;
    cin >> nCount;
    cin.ignore();

    for (int i=0; i<nCount; i++) {
        getline(cin, lecTime);
        inCommands.push_back(lecTime);
    }

    for (int i=0; i<inCommands.size(); i++) {
        string incomm = inCommands[i];
        char temp_incomm[10] = {0, };
        strcpy(temp_incomm, incomm.c_str());
        char *token = strtok(temp_incomm, " ");
        LectureTime inlec;
        inlec.start = token[0]-48;
        token = strtok(NULL, " ");
        inlec.end = token[0]-48;
        lecList.push_back(inlec);
    }

    vector<LectureTime> outLec;
    bool flag = false;
    outLec.push_back(lecList[0]);
    for (int i=1; i<lecList.size(); i++) {
        for (int j=0; j<outLec.size(); j++) {
            if ((lecList[i].start > outLec[j].start) && (lecList[i].start < outLec[j].end)) {
                flag = false;
                break;
            } else if ((lecList[i].end > outLec[j].start) && (lecList[i].end < outLec[j].end)) {
                flag = false;
                break;
            } else {
                flag = true;
            }
        }
        if (flag == true) {
            outLec.push_back(lecList[i]);
            ret++;
        }
    }

    cout << ret;

    return 0;
}

int s_array[100][100];
void snail_array() {
    int N, M, index=1;
    scanf("%d", &N);
    scanf("%d", &M);

    int i=0, j=0; 
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            s_array[i][j] == 0;
        }
    }

    i=0;j=0;
    s_array[i][j] = index++;

    while (index<=M*N) {
        while (j<M-1 && (s_array[i][j+1] == 0)) {
            s_array[i][++j] = index++;
        }

        while (i<N-1 && (s_array[i+1][j] == 0)) {
            s_array[++i][j] = index++;
        }

        while (j>0 && (s_array[i][j-1] == 0)) {
            s_array[i][--j] = index++;
        }

        while (i>0 && (s_array[i-1][j] == 0)) {
            s_array[--i][j] = index++;
        }
    }

    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            printf("%d ", s_array[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return ;
}

//https://softeer.ai/practice/7727 (함께하는 효도)
struct Friends_Coords {
    int lat;
    int lon;
};

int countOffruits[4][4] = {{20, 26, 185, 80}, {100, 20, 25, 80}, {20, 20, 88, 99}, {15, 32, 44, 50}};
int visited[4][4] = {{0, }};

Friends_Coords lookingForHighestCoord(Friends_Coords coor, int N) {
    Friends_Coords fCoords;
    int standard = 0;

    // standard = countOffruits[coor.lat][coor.lon];
    //left
    if (coor.lon > 0) {
        if ((standard < countOffruits[coor.lat][coor.lon-1]) && (visited[coor.lat][coor.lon-1] != 1)) {
            standard = countOffruits[coor.lat][coor.lon-1];
            fCoords.lat = coor.lat;
            fCoords.lon = coor.lon-1;
        }
    }
    //right
    if (coor.lon < N-1) {
        if ((standard < countOffruits[coor.lat][coor.lon+1]) && (visited[coor.lat][coor.lon+1] != 1)) {
            standard = countOffruits[coor.lat][coor.lon+1];
            fCoords.lat = coor.lat;
            fCoords.lon = coor.lon+1;
        }
    }
    //top
    if (coor.lat > 0) {
        if ((standard < countOffruits[coor.lat-1][coor.lon]) && (visited[coor.lat-1][coor.lon] != 1)) {
            standard = countOffruits[coor.lat-1][coor.lon];
            fCoords.lat = coor.lat-1;
            fCoords.lon = coor.lon;
        }
    }
    //bottom
    if (coor.lat < N-1) {
        if ((standard < countOffruits[coor.lat+1][coor.lon]) && (visited[coor.lat+1][coor.lon] != 1)) {
            standard = countOffruits[coor.lat+1][coor.lon];
            fCoords.lat = coor.lat+1;
            fCoords.lon = coor.lon;
        }
    }

    return fCoords;
}

int hyodo_together() {
    int N=4, M=2;
    // scanf("%d", &N);
    // scanf("%d", &M);

    // countOffruits = new int*[N];
    // visited = new int*[N];
    // for (int i=0; i<N; i++) {
    //     countOffruits[i] = new int[N];
    //     visited[i] = new int [N];
    //     memset(visited[i], 0, N);
    // }

    //input outcomes of fruits
    // for (int i=0; i<N; i++) {
    //     for (int j=0; j<N; j++) {
    //         int temp;
    //         scanf("%d", &temp);
    //         countOffruits[i][j] = temp;
    //     }
    // }

    //input coords
    Friends_Coords fCoords;
    vector<Friends_Coords> vfCoords;
    // for (int i=0; i<M; i++) {
    //     int temp;
    //     scanf("%d", &temp);
    //     fCoords.lon = temp-1; 
    //     scanf("%d", &temp);
    //     fCoords.lat = temp-1;

    //     vfCoords.push_back(fCoords);
    // } 

    vfCoords.push_back({1,2});
    vfCoords.push_back({2,3});


    //find the highest score.
    vector<Friends_Coords> resCoords;
    Friends_Coords curCoord;
    int standard = 0;
    for (int i=0; i<vfCoords.size(); i++) {
        curCoord.lat = vfCoords.at(i).lat-1;
        curCoord.lon = vfCoords.at(i).lon-1;
        visited[curCoord.lat][curCoord.lon] = 1;
        standard += countOffruits[curCoord.lat][curCoord.lon];
        printf("lat:%d lon:%d value:%d\n", curCoord.lat, curCoord.lon, countOffruits[curCoord.lat][curCoord.lon]);
        for (int j=0; j<3; j++) {
            Friends_Coords highestCoord = lookingForHighestCoord(curCoord, N);
            printf("lat:%d lon:%d value:%d\n", highestCoord.lat, highestCoord.lon, countOffruits[highestCoord.lat][highestCoord.lon]);
            standard += countOffruits[highestCoord.lat][highestCoord.lon];
            visited[highestCoord.lat][highestCoord.lon] = 1;
            printf("%d\n", standard);
            curCoord = highestCoord;
        }
    }


    printf("final: %d\n", standard);

    return 1;
}

// #include <cstdio>
// #include <algorithm>
// using namespace std;
// pair<int,int> a[1000000];
// int N,ans;

// // https://softeer.ai/practice/6291
// int LectureRoom2() {
//     scanf("%d",&N);
//     for(int i=0;i<N;i++) scanf("%d %d",&a[i].second,&a[i].first);
//     sort(a,a+N);
//     for(int i=0;i<N;i++){
//         int end = a[i].first;
//         ans++;
//         printf("1111 end: %d first: %d ans: %d\n",end,a[i].first, ans);
//         bool ok=0;
//         for(int j=i+1;j<N;j++){
//             if(end<=a[j].second){
//                 i=j-1;
//                 ok=1;
//                 printf("2222 end: %d second: %d ans: %d\n",end,a[j].second, ans);
//                 break;
//             }
//         }
//         if(!ok) break;
//     }
//     printf("%d",ans);
// }

// https://softeer.ai/practice/6294
#define _CRT_SECURE_NO_WARNINGS
struct section {
    int start;
    int end;
};
section sec[10000];
int K[10000];

int main(int argc, char** argv) {
    // int nCount, num, index=0;
    // scanf("%d_%d", &nCount, &num);
    // getchar();
    // char* strScore = (char*)malloc(10001000);
    // memset(strScore, 0, 10001000);
    // scanf("%s", strScore);
    // char* token = strtok(strScore, "_");
    // while(token!=NULL) {
    //     K[index++] = atoi(token);
    //     token = strtok(NULL, "_");
    // }
    // for (int i=0; i<num; i++) {
    //     scanf("%d_%d", &sec[i].start, &sec[i].end);
    // }

    // float average = 0.0f;
    // for (int i=0; i<num; i++) {
    //     for (int j=sec[i].start-1; j<sec[i].end; j++) {
    //         average += K[j];
    //     }
    //     printf("%0.2f\n", average/(sec[i].end-sec[i].start+1));
    //     average = 0.0f;
    // }
    // free(strScore);

    //spiral numbering [2024.02.19]
    int ans = hyodo_together();

    return 0;
}