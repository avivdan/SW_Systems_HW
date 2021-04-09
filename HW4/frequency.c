#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node{// what they defined us
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
    boolean isLeaf;
} node;


//create root of new trie
struct node* setNewNodeRoot()
{
    struct node* bop = (struct node*)malloc(sizeof(node));
    for (int i = 0; i < NUM_LETTERS; i++)
        bop->children[i] = NULL;
    return bop;
}
//init the new char to the trie
struct node* setNewNode(char c)
{
    struct node* bop = (struct node*)malloc(sizeof(node));
    bop->letter = c;
    for (int i = 0; i < NUM_LETTERS; i++)
        bop->children[i] = NULL;
    bop->isLeaf = FALSE;
    return bop;
}
// Iterative function to insert a string in Trie
void insert(node *head, char* str)
{
    // start from root node
    struct node* curr = head;
    while (*str>'a'-1 && *str<'z'+1)
    {
        // create a new node if path doesn't exists
        if (curr->children[*str - 'a'] == NULL)
            curr->children[*str - 'a'] = setNewNode((char)(*str));
        // go to next node
        curr = curr->children[(int)(*str - 'a')];
        // move to next character
        str++;
    }
    // mark current node as leaf
    curr->count++;
    curr->isLeaf = TRUE;
}
//return 1 if the string is in the trie structure, else return 0
int search(node *head, char* str)
{
    // return 0 if Trie is empty
    if (head == NULL)
        return 0;

    struct node* curr = head;
    while (*str)
    {
//        char *tempStr = (str+1);
        if(curr->isLeaf&&(str+1) == NULL)
            return 1;

        // go to next node
        curr = curr->children[*str - 'a'];

        // if string is invalid (reached end of path in Trie)
        if (curr == NULL)
            return 0;

        // move to next character
        str++;
    }

    // if current node is a leaf and we have reached the
    // end of the string, return 1
    return curr->isLeaf;
}
//*************************
boolean haveChildren(node *curr){
    for (int i = 0; i < NUM_LETTERS; ++i) {
        if(curr->children[i])
            return TRUE;
    }
    return FALSE;
}
// Recursive function to delete a string in Trie
//two** to delete in struct
int deletion(node **curr, char* str)
{
    // return if Trie is empty
    if (*curr == NULL)
        return 0;

    // if we have not reached the end of the string
    if (*str)
    {
        // recur for the node corresponding to next character in
        // the string and if it returns 1, delete current node
        // (if it is non-leaf)
        if (*curr != NULL && (*curr)->children[*str - 'a'] != NULL &&
            deletion(&((*curr)->children[*str - 'a']), str + 1) &&
            (*curr)->isLeaf == 0)
        {
            if (!haveChildren(*curr))
            {
                free(*curr);
                (*curr) = NULL;
                return 1;
            }
            else {
                return 0;
            }
        }
    }

    // if we have reached the end of the string
    if (*str == '\0' && (*curr)->isLeaf)
    {
        // if current node is a leaf node and don't have any children
        if (!haveChildren(*curr))
        {
            //if the word count is more then one we decrease the count of the last char in word
            //should be checked first !
            if((*curr)->count > 1) {
                (*curr)->count--;
                return 0;// don't delete its parent nodes;
            }else{
                free(*curr); // delete current node
                (*curr) = NULL;
                return 1; // delete non-leaf parent nodes
            }
        }
            // if current node is a leaf node and have children
        else{
            // mark current node as non-leaf node (DON'T DELETE IT)
            (*curr)->isLeaf = 0;
            return 0;// don't delete its parent nodes
        }
    }
    return 0;
}
//recycled search but check the count of the end character
int howManyOfMe(node *head, char* str){
    // return 0 if Trie is empty
    if (head == NULL)
        return 0;

    struct node* curr = head;
    while (*str)
    {
        if(curr->isLeaf&&(str+1) == NULL)
            return 1;

        // go to next node
        curr = curr->children[*str - 'a'];

        // if string is invalid (reached end of path in Trie)
        if (curr == NULL)
            return 0;

        // move to next character
        str++;
    }
    return curr->count;
}
//in case deletion mean that we should delete all words
void getRidOfMe(node *head, char* str){
    int SomeOfMe = howManyOfMe(head, str);
//    printf("%d", SomeOfMe);
    for (int i = 0; i < SomeOfMe; ++i) {
        deletion(&head, str);
    }
}
//*******************888
//destroy!
void destroy(node* root)
{
    for(int i=0; i<NUM_LETTERS; i++)
    {
        if(root->children[i] != NULL)
        {
            destroy(root->children[i]);//no wordarray
        }
    }
    free(root);
}
//*****************************************************************************************
/**
 * valgrind problem is with the use of pos, because we not initialize it in the function we got problem.
 * but the destroy work great!
 */
//print str
void printStr(char *str, int pos){
    int tempPos = pos;
    while( tempPos > 0){
        printf("%c",str[pos - tempPos]);// 0 -> pos
        tempPos--;
    }
}
//print all words
void printAllWords(node* root, char* wordArray, int pos)
{
    if(root == NULL)
        return;
    if(root->isLeaf)
    {
        printStr(wordArray, pos);
        printf(" %ld \n", root->count);// print the Count of the word and
    }
    for(int i=0; i<NUM_LETTERS; i++)
    {
        if(root->children[i] != NULL)
        {
            wordArray[pos] = root->children[i]->letter;
            printAllWords(root->children[i], wordArray, pos+1);
            root->children[i]->letter = 0;
        }
    }
}
//print all words in reverse
void printAllWordsInReverse(node* root, char* wordArray, int pos)
{
    if(root == NULL)
        return;
    if(root->isLeaf)
    {
        printStr(wordArray, pos);
        printf(" %ld \n", root->count);// print the Count of the word and
    }
    for(int i=1; i<NUM_LETTERS+1; i++)
    {
        if(root->children[NUM_LETTERS-i] != NULL)
        {
            wordArray[pos] = root->children[NUM_LETTERS-i]->letter;
            printAllWordsInReverse(root->children[NUM_LETTERS-i], wordArray, pos+1);
            root->children[NUM_LETTERS-i]->letter = 0;
        }
    }
}
//*****************************************************************************************


int getWordSize(char *word)
{
    int count = 0;
    char *ptr = word;
    while(*ptr != ' ' && *ptr != '\t' && *ptr != '\n' && *ptr != EOF && *ptr != '\0')
    {
        if ((*ptr > 'A' - 1 && *ptr < 'Z' + 1) || (*ptr > 'a' - 1 && *ptr < 'z' + 1)){
            count = count + 1;
        }
        ptr = ptr + 1;
    }
    return count;
}


int getword(char *word)
{
    int count = 0;
    char *ptr = word;
    while(*ptr != ' '&& *ptr != '\n' && *ptr != '\t' &&  *ptr != '\0' && *ptr != '\r')
    {
        count = count + 1;
        ptr = ptr + 1;
    }
    return count;
}
//adapt to our function
int HeyWord(node* head, char *str){
    int wordSize = getWordSize(str);
    char word [wordSize + 3];
    memset(word, 0, (wordSize+1) * sizeof(char));


    int index = 0, count = 0;
    while (*str != ' ' && *str != '\t' && *str != '\n' && *str != EOF && *str != '\0')
    { //space between words or finish text or line
        if ((*str > 'A' - 1 && *str < 'Z' + 1) || (*str > 'a' - 1 && *str < 'z' + 1)) { //word is in format
            if (*str > 'A' - 1 && *str < 'Z' + 1) {
                word[index] = tolower(*str);;
            } else {
                word[index] = *str;
            }
            index++;
        } //if they are not need to be in *str go to next loc in array chars
        str++;
        count++;
    }
    int a = getword(word);
    char *str2 = malloc(a+1);

    for (int j = 0; j < a; j++)
    {
        str2[j] = word[j];
    }
    str2[a] = '\0';
    insert(head,str2);// insert to str to trie
    free(str2);
    return count;
}




//*****************************************************************************************












int main(int argc, char* argv[]){
//    struct node* root = setNewNodeRoot();
//    char *line = NULL;
//    size_t size;
//
//    int maxi = 0;

//    int c;
//    boolean b = FALSE;
//    int index = 0;
//    int maxi = 0;
//    int startMalloc = 10;
//    char *str;
//    str = (char *) malloc(startMalloc);
//    c = getchar();
//    while (c != EOF)
//    {
//
//        if (c > 'A' - 1 && c < 'Z' + 1 || c > 'a' - 1 && c < 'z' + 1)// while getting word
//        {
//
//            str[index] = c; // assign char
////            str[index + 1] = '0'; // clear the next char
//            if(index +1 > startMalloc){
//                startMalloc += 10;
//                str = (char *) realloc(str, startMalloc);
//            }
//            index++;
//            if(!b){
//                b = TRUE;
//            }
//        }
//
//        if(c == ' ' || c == '\t' || c == '\n' || c == '\0'){
//            if(b){
//                if(index > maxi){
//                    maxi = index;
//                }
//                index = 0;
////                int = getWordSize(str);
//                HeyWord(root, str); //put str in root
//                str[index] = 0;
//                b = FALSE;
//            }
//        }
//        c = getchar();
//    }
//    if (b)
//    {
//        if (index > maxi)
//        {
//            maxi = index;
//        }
//        index = 0;
////        int = getWordSize(str);
//        HeyWord(root, str); //put str in root
//        b = FALSE;
//    }
//free(str);


    struct node* root = setNewNodeRoot();
    char *line = NULL;
    size_t size;

    int maxi = 0;


     while(getline(&line, &size, stdin) != -1) {
         while (*line != '\n' && *line != EOF)
         { //we get only one line
             if((*line> 'A' - 1 && *line < 'Z' + 1) || (*line > 'a' - 1 && *line < 'z' + 1)){
                 int temp = getWordSize(line);
                 if(temp > maxi){
                     maxi = temp;
                 }
                 int a = HeyWord(root, line);
                 line = line + a;
             }else{
                 line++;
             }
         }

         // line = NULL;

     }
//     free(line);

    //maxi here problem
    char wordArray[maxi + 20];
    memset(wordArray, 0, (maxi+1) * sizeof(char));
    if(argc < 2)
        printAllWords(root, wordArray,0);
    else{
        printAllWordsInReverse(root, wordArray,0);
    }
    destroy(root);
//    printf("%d", maxi);

    return 0;
}






