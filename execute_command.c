#include "shell.h"

/**
 * execute_command -
 *
 * Return: void
 */


void execute_command(char** args)
{
    if (strcmp(args[0], "cd") == 0)
      {
        // Commande "cd"
        if (args[1] == NULL)
	  {
            // Pas de répertoire spécifié, aller au répertoire personnel de l'utilisateur
            chdir(getenv("HOME"));
        }
	else
	  {
            if (chdir(args[1]) != 0) {
                printf("Error navigating to specified directory\n");
          }
        }
    }
    else if (strcmp(args[0], "exit") == 0)
      {
        // Commande "exit", quitter le programme
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(args[0], "env") == 0)
      {
        // Commande "env", afficher les variables d'environnement
        char** env_var = environ;
        while (*env_var)
	  {
            printf("%s\n", *env_var);
            env_var++;
        }
    }
    else
      {
        char* bin_path = find_bin_path(args[0]);
        if (bin_path != NULL)
	  {
            pid_t pid = fork();
            if (pid == 0)
	      {
                // Processus enfant
                execvp(args[0], args);
                exit(EXIT_FAILURE);
            }
	    else if (pid < 0)
	      {
                // Erreur lors de la création du processus enfant
                printf("Error creating child process\n");
            }
	    else
	      {
                // Processus parent
                wait(NULL);
            }
            free(bin_path);
        }
	else
	  {
            printf("Command not found: %s\n", args[0]);
        }
    }
}
