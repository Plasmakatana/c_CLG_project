#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
char usernameforpost[50];
struct User {
    char name[50];
    char email[50];
    char password[50];
    int is_logged_in;
};

struct Images{
	char img[1000];
	char name[50];
};

struct Post {
    char author[50];
    char content[200];
    char comment[200];
    int likes;
};
void sign_up(void/*struct User *users, int num_users, char *username, char *password*/) {
    							FILE* fp;
    							char user[20],userch[20],pass[20],passch[20];
								char temp;
								printf("enter username: ");
								scanf("%c",&temp);
								scanf("%[^\n]", user);    
    							printf("enter password: ");
								scanf("%c",&temp);
								scanf("%[^\n]", pass);
								fp = fopen("users.txt", "a+");
 								rewind(fp);
    							if (NULL == fp) {
        							printf("file can't be opened \n");
        							exit(1);
    							}
    							else
    							{
    								fprintf(fp,"%s %s\n",user,pass);
								}
								fclose(fp);
	/*int i;
	for (i = 0; i < num_users; i++) 
	{
        if (strcmp(users[i].name, username) == 0) 
		{
            printf("Error: username already exists\n");
            users[num_users].is_logged_in = 0;
            return num_users;
        }
    }
    strcpy(users[num_users].name, username);
    strcpy(users[num_users].password, password);
    users[num_users].is_logged_in = 1;
    printf("Sign up successful\n");

    return num_users + 1;*/
}

void log_in(void/*struct User *users, int num_users, char *username, char *password*/) {
								FILE* fp;
    							char user[20],userch[20],pass[20],passch[20];
								char temp;
								int isloggedin;
								printf("enter username: ");
								scanf("%c",&temp);
								scanf("%[^\n]", user);    
    							printf("enter password: ");
								scanf("%c",&temp);
								scanf("%[^\n]", pass);
								fp = fopen("users.txt", "r");
 								rewind(fp);
    							if (NULL == fp) {
        							printf("file can't be opened \n");
    							}
    							else
    							{
    								while(!feof(fp)){
									
									fscanf(fp,"%s %s\n",userch,passch);
    								if(strcmp(user,userch)==0&&strcmp(pass,passch)==0)
    								{
    									printf("logged in!");
    									isloggedin=1;
    									strcpy(usernameforpost,userch);
									}
									}
									if(isloggedin!=1){
										printf("wrong login username or password\nwrong login username or password\nwrong login username or password\nwrong login username or password\n");
									
									}
								}
								fclose(fp);
	/*int usrnmpresent=0;
	int i;
	for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, username) == 0 && strcmp(users[i].password, password) == 0) {
            usrnmpresent+=1;
			if (users[i].is_logged_in==1) {
                printf("Error: already logged in\n");
                //users[num_users].is_logged_in = 1;
                return num_users;
            } else {
                users[i].is_logged_in = 1;
                printf("Log in successful\n");
                return num_users;
            }
        }
        else{
        	
		}
	}
	if(usrnmpresent>=1){
		printf("Log in successful\n");
	}
	else{
		printf("Error: invalid username or password\n");
	}
		
    

    
    return num_users;*/
}


/*int log_out(struct User *users, int num_users, char *username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, username) == 0) {
            if (!users[i].is_logged_in) {
                printf("Error: not logged in\n");
                return num_users;
            } else {
                users[i].is_logged_in = 0;
                printf("Log out successful\n");
                return num_users;
            }
        }
    }

    printf("Error: username not found\n");
    return num_users;
}

int sign_out(struct User *users, int num_users, char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, username) == 0 && strcmp(users[i].password, password) == 0) {
            strcpy(users[i].name, "");
            strcpy(users[i].password, "");
            users[i].is_logged_in = 0;
            printf("Sign out successful\n");
            return num_users - 1;
        }
    }

    printf("Error: invalid username or password\n");
    return num_users;
}
void signup(struct User userdb){
	char emailfn[50];
	char usrnm[50];
	char pwd[50];
	printf("enter email:");
	scanf("%s ",emailfn);
	printf("enter username u want:");
	scanf("%s ",usrnm);
	printf("enter password:");
	scanf("%s ",pwd);
	strcpy(userdb.email,emailfn);
	strcpy(userdb.name,usrnm);
	strcpy(userdb.password,pwd);
}
char login(struct User userdb){
	char usrnm[50];
	char pwd[50];
	printf("enter username:");
	scanf("%s ",usrnm);
	printf("enter password:");
	scanf("%s ",pwd);
	printf("logged in");

}*/

void displayPost(struct Post post) {
	printf("                  %s\n", post.author);
	printf("                  _____________________________\n");
    printf("                  %s\n\n\n", post.content);
    printf("                  _____________________________\n");
	printf("                   likes:%d        ",post.likes);
    printf("comments:%s\n\n\n\n",post.comment);
}
void addPost(struct Post posts[], int postCount,char author[50]) 
{
    //char author[50];
    char content[200];
    printf("Enter the post content:\n");
    //scanf("%s ",author);
    strcpy(posts[postCount].author, author);
    //printf("Enter the post content: \n");
    //scanf("%[^\n]s",content);
    char temp;
	scanf("%c",&temp);
	scanf("%[^\n]", content);
	//fgets(content,200,stdin);
	//getch();    
    strcpy(posts[postCount].content, content);
}
int main() {
    struct User users[100];
    struct Post posts[350];
    struct Images image[10];
	int index=0;
	//structure data for posts
	FILE *ptr1;
	FILE *ptr2;    
    ptr1 = fopen("usernames.txt", "r+");
    ptr2 = fopen("tweets.txt", "r+");
    rewind(ptr1);
    rewind(ptr2);
    if (NULL == ptr1) {
        printf("file can't be opened \n");
    }    
    else {
    	while(!feof(ptr1)){		
        fscanf(ptr1,"%[^\n]\n",posts[index].author);
        fscanf(ptr2,"%[^\n]\n",posts[index].content);
        posts[index].likes=rand()%1000-1;
        index++;
		}
	}
	int i=50,a,x,j=51,k=0,img;	
	int counter=1;
	char postusrnm[50],pwd[50];
		begin_loop:
	while(i>=0){
				//system("cls");		
				char comment[200];
    			printf("\n"); 				   							
				printf(" ____________\n");
				printf("/            \\ \n");
				printf("|TEXTNET.COM |   %c\n",153);
				printf("\\____________/ \n");
				displayPost(posts[i]);
				printf("1.Previous\n2.Next\n3.Like\n4.Comment\n5.New post\n6.Signup\n7.Login\n8.See images\n9.Exit");
				scanf("%d",&a);
				switch(a)
				{
					case 1:
						i--;
						system("cls");
						break;
					case 2:
						i++;
						system("cls");
						break;
					case 3:
						switch(counter)
						{
							case 1:
								posts[i].likes++;
								counter=2;
								break;
							case 2:
								posts[i].likes--;
								counter=1;
								break;
							default:
								break;
						}
						system("cls");
						break;
					case 4:
						printf("write comment");
						//getch();
						//scanf("%[^\n]s",comment);
						//fgets(comment,200,stdin);
						char temp;
						scanf("%c",&temp);
						scanf("%[^\n]", comment);
						strcpy(posts[i].comment,comment);
						system("cls");
						//displayPost(posts[i]);
						break;
					case 5:
						strcpy(postusrnm,usernameforpost);
						if(strlen(postusrnm)>0)
						{
						addPost(posts,j,postusrnm);
						system("cls");
						i=j;
						j++;
						}
						else
						{
							system("cls");
							printf("!NOT LOGGED IN! !NOT LOGGED IN! !NOT LOGGED IN! !NOT LOGGED IN! !NOT LOGGED IN!\n");
						}
						break;
					case 6:
						//printf("enter username:\n");
						//char temp;
						//scanf("%c",&temp);
						//scanf("%[^\n]", postusrnm);
						//scanf("%s",postusrnm);
						//printf("enter password:\n");
						//scanf("%c",&temp);
						//scanf("%[^\n]", pwd);
						//scanf("%s",pwd);
						sign_up(/*users,100,postusrnm,pwd*/);
						system("cls");
						k++;
						break;
					case 7:
						//printf("enter username:\n");
						//char temp;
						//scanf("%c",&temp);
						//scanf("%[^\n]", postusrnm);
						//scanf("%s",postusrnm);
						//printf("enter password:\n");
						//scanf("%c",&temp);
						//scanf("%[^\n]", pwd);
						//scanf("%s",pwd);
						log_in(/*users,100,postusrnm,pwd*/);
						//system("cls");
						k++;
						break;
					case 8:
						printf("1.einstein\n2.charlie chaplin\n3.terminator\n4.jfk\n5.napolean\n6.george washington");
						scanf("%d",&img);
						switch(img)
						{
							case 1:
								system("cls");    
    							FILE* ptr;
    							char ch;    
    							ptr = fopen("einstein.txt", "r");
 
    							if (NULL == ptr) {
        							printf("file can't be opened \n");
    							}
 
    
    							do {
        							ch = fgetc(ptr);
        							printf("%c", ch);
 
        			// Checking if character is not EOF.
        			// If it is EOF stop reading.
    							} while (ch != EOF);
    							break;
    						case 2:
								system("cls");    
    							ptr = fopen("chaplin.txt", "r");
 
    							if (NULL == ptr) {
        							printf("file can't be opened \n");
    							}
 
    
    							do {
        							ch = fgetc(ptr);
        							printf("%c", ch);
 
        							
    							} while (ch != EOF);
 
    
    							fclose(ptr);
    							break;
    						case 3:
								system("cls");    
    							ptr = fopen("terminator.txt", "r");
 
    							if (NULL == ptr) {
        							printf("file can't be opened \n");
    							}
 
    
    							do {
        							ch = fgetc(ptr);
        							printf("%c", ch);
 
        							
    							} while (ch != EOF);
 
    
    							fclose(ptr);
    							break;
    						case 4:
								system("cls");    
    							ptr = fopen("jfk.txt", "r");
 
    							if (NULL == ptr) {
        							printf("file can't be opened \n");
    							}
 
    
    							do {
        							ch = fgetc(ptr);
        							printf("%c", ch);
 
        							
    							} while (ch != EOF);
 
    
    							fclose(ptr);
    							break;
    						case 5:
								system("cls");    
    							ptr = fopen("napolean.txt", "r");
 
    							if (NULL == ptr) {
        							printf("file can't be opened \n");
    							}
 
    
    							do {
        							ch = fgetc(ptr);
        							printf("%c", ch);
 
        							
    							} while (ch != EOF);
 
    
    							fclose(ptr);
    							break;
    						case 6:
								system("cls");    
    							ptr = fopen("george.txt", "r");
 
    							if (NULL == ptr) {
        							printf("file can't be opened \n");
    							}
 
    
    							do {
        							ch = fgetc(ptr);
        							printf("%c", ch);
 
        							
    							} while (ch != EOF);
 
    
    							fclose(ptr);
    							break;
    						default:
    							system("cls");
    							break;
							}
    					break;	
						
					case 9:
						exit(0);							
					default:
						break;
						goto begin_loop;						
				}
			}
	return 0;
}


