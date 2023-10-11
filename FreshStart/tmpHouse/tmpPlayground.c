//read enter new name
                            //read enter new name
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read enter new name

                            //input new name
                            char inputNewName[100];
                            scanf("%s",inputNewName);
                            write(sockfd,&inputNewName,sizeof(inputNewName));
                            //input new name

                            //read msg updation
                            bzero(buffer,buffsz);
                            read(sockfd,buffer,buffsz);
                            printf("Server:\n %s\n",buffer);
                            //read msg updation
                            break;