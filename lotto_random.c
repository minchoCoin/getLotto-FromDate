#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swap(int *a, int *b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    return 0;
}
int main() {
  time_t rawtime;
  time_t fix_time;
  struct tm* timeinfo;
  int year, month, day, hour, minute, second;
  char* weekday[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                     "Thursday", "Friday", "Saturday"};
  int lotto_type; // 0 : lotto, 1 : pension

  int lotto[5][6];
  int pension[5][7];
  /* 사용자로 부터 날짜를 입력 받는다. */
  printf("Enter year: ");
  scanf("%d", &year);
  printf("Enter month: ");
  scanf("%d", &month);
  printf("Enter day: ");
  scanf("%d", &day);
  printf("Enter hour");
  scanf("%d",&hour);
  printf("Enter minute");
  scanf("%d",&minute);
  printf("Enter second");
  scanf("%d",&second);

  printf("Enter lotto type : lotto(0), pension(1)")
  scanf("%d",&lotto_type);

  /* rawtime 에 time 함수로 현재 시간 정보로 세팅한 뒤,
     사용자로 부터 입력받은 데이터로 년/월/일 정보를 수정한다. */
  time(&rawtime); // rawtime=time(NULL);
  timeinfo = localtime(&rawtime);
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;
  timeinfo->tm_hour = hour;
  timeinfo->tm_min = minute;
  timeinfo->tm_sec = second;

  /* mktime 함수를 호출하면 년/월/일 데이터에 따라
     tm_wday 와 tm_yday 를 설정한다. 이 때 리턴되는 time_t 데이터는 사용하지
     않는다.*/
  fix_time = mktime(timeinfo);
  printf("시간환산 : %d",fix_time);
  srand(fix_time);
  int i,j,k;
  int random
  if(lotto_type = 0){
      for(i=0;i<4;i++){
        for(j=0;j<6;j++){
          random = rand()%45 + 1;
          for(k=0;k<j && lotto[i][k]!=random;k++) {}
          if(k<j){ //중복있음
             j--;
          }

          else{ // 중복없음
              lotto[i][j] = random;
          }
          
      }
  }
    //정렬
    for(i=0;i<4;++i){
        for(j=0;j<6;j++){
            for(k=j;k<6;k++){
                if(lotto[i][j]>lotto[i][k])
                {
                    swap(lotto[i][j],lotto[i][k]);
                }
            }
        }
    }

    for(i=0;i<4;++i){
      for(j=0;j<6;++j){
          printf("%d "lotto[i][j]);
      }
      printf("\n");
  }
  }

  if(lotto_type = 1){
      for(i=0;i<4;i++){
          for(j=0;j<7;j++){
              if(j==0) {pension[i][j] = random%5 + 1};
              else {pension[i][j] = random%10};
          }
      }
      for(i=0;i<4;++i){
        for(j=0;j<7;++j){
            if(j==0) {printf("%d | "lotto[i][j]);}
            else {printf("%d "lotto[i][j]);}
          
        }
      printf("\n");
  }
  }


  printf("That day is a %s.\n", weekday[timeinfo->tm_wday]);

  return 0;
}
