#include<stdio.h>
#include<Stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "student.h"
/* 학생 정보를 입력받아 데이터베이스 파일에서 삭제한다. */

int main(int argc, char *argv[]) {
    int fd, id;
    char c;
    struct student record;
   
    if (argc < 2) {
        fprintf(stderr, "사용법 : %s file\n", argv[0]);
        exit(1);
    }
   
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("삭제할 학생의 학번 입력: ");
    
        if (scanf("%d", &id) == 1) {
            lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
            
            while() {
                if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
                    printf("학번:%8d\t 이름:%4s\t 점수:%4d\n", record.id, record.name, record.score);

                    if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
                        lseek(fd, (long) -sizeof(record), SEEK_CUR);
                    }

                    lseek(fd, (long) -sizeof(record), SEEK_CUR);
                    write(fd, (char *) &record, sizeof(record));
                } else {
                    printf("레코드 %d 없음\n", id);
                    break;
                }
            }

            printf("삭제되었습니다.\n");

        } else {
            printf("입력오류\n");
        }
            printf("계속하겠습니까?(Y/N)");
            scanf(" %c",&c);
    } while (c == 'Y');
}