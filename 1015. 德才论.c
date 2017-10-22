#include <stdio.h>
struct Node{
    int sum;
    int level;
    int id;
    int virtue;
    int talent;
};
int main() {
    int j = 0;
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    struct Node array[N],tmp;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &tmp.id, &tmp.virtue, &tmp.talent);
        if (tmp.talent >= L && tmp.virtue >= L) {
            array[j] = tmp;
            array[j].sum = array[j].talent+array[j].virtue;
            if (array[j].virtue >= H && array[j].talent >= H) array[j].level = 1;
            else if (array[j].virtue >= H && array[j].talent < H) array[j].level = 2;
            else if (array[j].virtue < H && array[j].talent < H && array[j].virtue>=array[j].talent)
                array[j].level = 3;
            else array[j].level = 4;
            j++;
        }
    }
    int count = j;
   // terrible !!! 运行超时 等学习排序了在解决吧！！
    for(int i=0; i< count-1; i++){
        for(j = i+1; j < count; j++){
            tmp = array[i];
            if(array[j].level < tmp.level){
                array[i] = array[j];
                array[j] = tmp;
            }else if(array[j].level == tmp.level){
                if(array[j].sum > tmp.sum){
                    array[i] = array[j];
                    array[j] = tmp;
                }else if(array[j].sum == tmp.sum){
                    if(array[j].virtue > tmp.virtue){
                        array[i] = array[j];
                        array[j] = tmp;
                    }else if(array[j].virtue == tmp.virtue){
                        if(array[j].id < tmp.id){
                            array[i] = array[j];
                            array[j] = tmp;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    for(j=0; j< count; j++){
        printf("%d %d %d\n", array[j].id, array[j].virtue, array[j].talent);
    }
}
