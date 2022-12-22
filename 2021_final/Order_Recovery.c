#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"
};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}

//

int find_match_pos(const char *str, const char *sub) {
    int len = strlen(str);
    int sub_len = strlen(sub);
    if (sub_len > len) return -1;

    for (int i = 0;i+sub_len-1 < len;i++) {
        int match = 1;
        for (int j = 0;j < sub_len;j++) {
            if (str[i+j] != sub[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}

char *find_goods(char *order) {
    int ans_id = -1;
    int ans_match;
    for (int i = 0;i < GOODS_SIZE;i++) {
        int match_pos = find_match_pos(names[i], order);
        if (match_pos == -1) continue;

        int upd = 0;
        if (ans_id == -1) {
            upd = 1;
        } else {
            if (ans_match > match_pos) {
                upd = 1;
            } else if (ans_match == match_pos) {
                int ans_len = strlen(names[ans_id]);
                int cur_len = strlen(names[i]);
                if (ans_len > cur_len) {
                    upd = 1;
                } else if (ans_len == cur_len) {
                    if (strcmp(names[ans_id], names[i]) > 0) { // names[i] is smaller
                        upd = 1;
                    }
                }
            }
        }
        if (upd) {
            ans_id = i;
            ans_match = match_pos;
        }
    }
    return names[ans_id];
}

void recovering_order(char *order, char **result) {
    char *str = malloc(sizeof(char) * (MAX_ORDER_SIZE * MAX_NAME_LEN));
    str[0] = '\0';
    char *tok = strtok(order, ":");
    int first = 1;
    while (tok != NULL) {
        if (!first) {
            strcat(str, "+");
        } else first = 0;
        strcat(str, find_goods(tok));
        tok = strtok(NULL, ":");
    }
    *result = str;
}
