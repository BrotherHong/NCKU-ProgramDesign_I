#include<stdio.h>

void printSpace(int n) {
    if (n <= 0) return;
    while (n--) {
        printf(" ");
    }
}

int main(void) {
    // input
    /*
    * leavesLayer: 三角形樹葉的層數
    * topLeavesHeight: 最上層三角形樹葉的高度
    * deltaLayerHeight: 下一層三角形樹葉比上一層還多的高度差
    * trunkWidth: 樹幹的寬度
    * trunkHeight: 樹幹的高度
    */
    int leavesLayer, topLeavesHeight, deltaLayerHeight;
    int trunkWidth, trunkHeight;
    scanf("%d%d%d", &leavesLayer, &topLeavesHeight, &deltaLayerHeight);
    scanf("%d%d", &trunkWidth, &trunkHeight);

    // initialize
    /*
    * maxWidth: 圖形所佔的最大寬度 (會是奇數)
    */
    int maxWidth = 2*(topLeavesHeight + deltaLayerHeight*(leavesLayer-1)) - 1;

    // print leaves
    /*
    * layer: 目前正在印 第 layer 層 的三角形樹葉
    * curLayerHeight: 目前正在印的這層三角形樹葉的高度
    */
    for (int layer = 1, curLayerHeight = topLeavesHeight; layer <= leavesLayer; layer++, curLayerHeight += deltaLayerHeight) {
        /*
        * row: 目前正在印這層三角形樹葉的 第 row 列
        * (layer == 1 ? 1 : 2): 若為最上層則從第一列開始印，若否，則從第二列開始印
        */
        for (int row = (layer == 1 ? 1 : 2); row <= curLayerHeight; row++) {
            /*
            * width: 此列的寬度
            * (maxWidth - width)/2 : 前面要印出的空格數
            */
            int width = 2*row-1;
            printSpace((maxWidth - width)/2);
            
            // 若為最後一列，則都印出#
            if (row == curLayerHeight) {
                for (int w=1;w <= width;w++) {
                    printf("#");
                }
            } else {
                for (int w=1;w <= width;w++) {
                    printf("%c", (w==1 || w == width ? '#' : '@'));
                }
            }
            printf("\n");
        }
    }

    // print trunk
    // 我相信你應該看得懂
    for (int h = 1;h <= trunkHeight;h++) {
        printSpace((maxWidth - trunkWidth)/2);
        for (int w = 1; w <= trunkWidth; w++) {
            printf("|");
        }
        printf("\n");
    }
    return 0;
}