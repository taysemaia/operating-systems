#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h> 
#include <stdlib.h>
#include <ctime>

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("# %d/%m/%Y "); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }




int main(int argc, char const *argv[])
{
	double tempodevida[6];
	pid_t pid, pid1, neto, neto1;
	time_t filho1[2], filho2[2], neto_1[2], neto_2[2], pai[2];
	std::string nascimento[5], morte[5];

	nascimento[0] = get_current_time();
	
	std::cout << "Pai nasceu às " << nascimento[0] << std::endl;

	pai[0] = time(NULL);
	sleep(14);
	pid = fork();


	if(pid < 0){ 

		std::cout << "Erro ao criar processo" << std::endl;
		return 1;
	}

	if(pid > 0) { //se for o pai
		//pai 

		sleep(2);							// os 2 sao executados ao msm tempo
		pid1 = fork();
		if (pid1 == 0){ // é o filho2
			nascimento[2] = get_current_time();
			std::cout << "Filho 2 nasceu às " << nascimento[2] << std::endl;
			neto1 = fork();

			if (neto1 == 0)
			{
				sleep(14);
				nascimento[4] = get_current_time(); //esse é o neto 2

				std::cout << "Neto 2 nasceu às " << nascimento[4] << std::endl;

				neto_1[0] = time(NULL);
				sleep(18);
				morte[4] = get_current_time();
				neto_1[1] = time(NULL);

				tempodevida[4] = (difftime(neto_1[0], neto_1[1])) * (-1);

				std::cout<< "Neto 2 nasceu às " << nascimento[4] << ", morreu às " << morte[4] << ", e viveu " << tempodevida[4] << " anos." << std::endl;


				exit(0);

			}
			else if(neto1 > 0){

				filho2[0] = time(NULL);
				sleep(30);
				filho2[1] = time(NULL); //filho 2 tbm
				morte[2] = get_current_time();
				tempodevida[3] = (difftime(filho2[0], filho2[1])) * (-1);

				std::cout<< "Filho 2 nasceu às " << nascimento[2] << ", morreu às " << morte[2] << ", e viveu " << tempodevida[3] << " anos." << std::endl;

				exit(0);
			}
		}

		else if(pid > 0){ //pai

			sleep(44);
			morte[0] = get_current_time();
			pai[1] = time(NULL);
			tempodevida[2] = (difftime(pai[0], pai[1])) * (-1);

			std::cout<< "Pai nasceu às " << nascimento[0] << ", morreu às " << morte[0] << ", e viveu " << tempodevida[2] << " anos." << std::endl;

			exit(0);
			
		}
	}
	else{
		nascimento[1] = get_current_time();

		std::cout << "Filho 1 nasceu às " << nascimento[1] << std::endl;    //filho 1

		filho1[0] = time(NULL);
		neto = fork();

		if(neto == 0){
			sleep(12);
			neto_1[0] = time(NULL);
			nascimento[3] = get_current_time();

			std::cout << "Neto 1 nasceu às " << nascimento[3] << std::endl;  //neto1

			sleep(12);
			morte[3] = get_current_time();
			neto_1[1] = time(NULL);
			tempodevida[0] = (difftime(neto_1[0], neto_1[1])) * (-1);

			std::cout<< "Neto 1 nasceu às " << nascimento[3] << ", morreu às " << morte[3] << ", e viveu " << tempodevida[0] << " anos." << std::endl;

			exit(0);
			
		}
		else if(neto > 0){
			filho1[0] = time(NULL);	//filho1
			sleep(30);
			filho1[1] = time(NULL);
			tempodevida[1] = (difftime(filho1[0], filho1[1])) * (-1);
			morte[1] = get_current_time();

			std::cout<< "Filho 1 nasceu às " << nascimento[1] << ", morreu às " << morte[1] << ", e viveu " << tempodevida[1] << " anos."<< std::endl;
			exit(0);
		}
	}


	return 0;
}