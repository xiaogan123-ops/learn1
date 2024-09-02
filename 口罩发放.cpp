#include <stdio.h>
#include <string.h>

typedef struct Person{
	char name[11];
	char id[21];
	int status;
	char time[6];
	int cnt;
}Person;

int main(){
	int d, p, i, j, k, t, s, len_id, itmp;
	Person person[1000], total[30000], tmp;
	int scnt = 0, tcnt = 0, flag = 0;
	
	scanf("%d%d", &d, &p); //输入数据
	for (i=0; i<30000; i++){
		total[i].cnt = 0;
	}
	for (i=0; i<d; i++){
		scanf("%d%d", &t, &s);
		scnt = 0;
	
		for (j=0; j<t; j++){ 
			scanf("%s %s %d %s", person[j].name, person[j].id, &person[j].status, person[j].time);
		
			flag = 0;
			len_id = strlen(person[j].id);
			person[j].cnt = 0;
			if (len_id != 18){
				continue;
			}
			for (k=0; k<tcnt; k++){
			
				if (strcmp(person[j].id, total[k].id) == 0){
					flag = 1;
					person[j].cnt = total[k].cnt; 
				
					if (person[j].status == 1){
						total[k].status = person[j].status;
					}
					break;
				}
			}
		
			if (flag==0 && len_id==18){
				total[tcnt] = person[j];
				tcnt++;
			}
		
		}
		for (j=0; j<t-1; j++){ //按照提交时间先后顺序排序
			for (k=j+1; k<t; k++){
				if (strcmp(person[j].time, person[k].time) > 0){
					tmp = person[j];
					person[j] = person[k];
					person[k] = tmp;
				}
			}
		}
		
		for (j=0; j<t; j++){
			len_id = strlen(person[j].id);
			if (len_id<18 || len_id>18){
				continue;
			}
		
			for (k=0; k<tcnt; k++){
				if (strcmp(person[j].id, total[k].id) == 0){
					if (total[k].cnt > 0){
						total[k].cnt++;
						if (total[k].cnt == p+1){
							total[k].cnt = 0;
						}
						person[j].cnt = total[k].cnt;
					}
				}
			}
			if (person[j].cnt==0){
				scnt++;
				person[j].cnt++;
				if (scnt <= s){
					printf("%s %s\n", person[j].name, person[j].id);
					for (k=0; k<tcnt; k++){
						if (strcmp(person[j].id, total[k].id) == 0){
							total[k].cnt = person[j].cnt;
						}
					}
				}
			}
		}
		

	}
	

	for (i=0; i<tcnt; i++){
		if (total[i].status == 1){
			printf("%s %s\n", total[i].name, total[i].id);
		}
	}
	
	return 0;
}
