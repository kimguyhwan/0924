#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>   

#define Key_a 97 // 'a' 문자의 ASCII 코드 값
#define Key_z 122 // 'z' 문자의 ASCII 코드 값
#define ALPHABET_COUNT (Key_z - Key_a + 1) // 알파벳 'a'부터 'z'까지의 총 개수 (26개)

// 두 문자 변수의 값을 교환하는 함수
void swap(char* a, char* b)
{
    char c = *a; // 'a'가 가리키는 값을 임시 변수 'c'에 저장
    *a = *b;     // 'a'가 가리키는 위치에 'b'가 가리키는 값을 할당
    *b = c;      // 'b'가 가리키는 위치에 임시 변수 'c'에 저장된 값을 할당
}

int main()
{
    srand(time(NULL)); // 난수 생성 시드를 현재 시간으로 초기화하여 매번 다른 난수열을 생성

    char random[ALPHABET_COUNT]; // 알파벳 26개를 저장할 문자형 배열 선언

    int i = 0;
    // 배열의 모든 요소를 0으로 초기화 (빈 칸 여부 확인용)
    for (i = 0; i < ALPHABET_COUNT; i++)
    {
        random[i] = 0;
    }

    // 'a'부터 'z'까지의 알파벳들을 배열에 무작위 순서로 중복 없이 채움
    for (i = 0; i < ALPHABET_COUNT; i++)
    {
        while (1) // 빈 칸을 찾을 때까지 반복
        {
            int rand_index = rand() % ALPHABET_COUNT; // 0부터 (ALPHABET_COUNT-1) 사이의 무작위 인덱스 생성
            if (random[rand_index] == 0) // 해당 인덱스의 칸이 비어있으면 (값이 0이면)
            {
                random[rand_index] = (char)(i + Key_a); // 현재 순서에 해당하는 알파벳을 할당
                break; // 다음 알파벳 처리를 위해 반복 종료
            }
        }
    }

    // 버블 정렬(Bubble Sort)을 수행 (오름차순 정렬)
    // 외부 반복문: 전체 배열을 탐색하는 횟수를 제어한다 (정렬될 때마다 탐색 범위 감소)
    for (i = 0; i < ALPHABET_COUNT - 1; i++)
    {
        // 내부 반복문: 인접한 두 요소를 비교하고 필요시 교환
        for (int j = 0; j < ALPHABET_COUNT - i - 1; j++)
        {
            // 현재 문자가 다음 문자보다 크면 (ASCII 값 기준)
            if (random[j] > random[j + 1])
            {
                swap(&random[j], &random[j + 1]); // swap 함수를 호출하여 두 문자의 위치를 교환
            }
        }
    }

    // 정렬된 알파벳들을 화면에 출력
    printf("---나 인간 김인직 일 한번 지질러보리라---\n");
    printf("인덱스\t알파벳\n");
    for (i = 0; i < ALPHABET_COUNT; i++)
    {
        printf("%d\t%c\n", i, random[i]);
    }
    printf("\n");

    return 0; 
}