/**
 * \brief The only one
 * At the end of the project, the compilation should be OK :)
*/
#include "interface.h"
#include "Configurator.h"

void main() {
	if(!initConfigurator()){
		system("clear");
		printf("BIKERFUL ! configurator doesn\'t exists\n");
		if(enterGlobsVariables(CONF_FILE_NAME)) printf("Succesfull saved parameters.\n");
			else printf("FAIL saved parameters...\n");
	}
	else
  		mainMenu(); // quite simply
}

/**
 * \author M. CHABAUD, G. DEL REY ,E. RENDRIA,M.SANMARTIN
 */

