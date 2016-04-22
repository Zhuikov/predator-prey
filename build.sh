#!/bin/bash

export PATH=$PATH:/opt/Qt5.5.0/5.5/gcc_64/bin/

build_release_version() {
	cd sources/Predator-prey
	qmake --version
	qmake
	if [ -e "Makefile" ]; then
		make --version
		make
		#todo вынести cd из ветви условия
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build release version failure!"
		#todo использоватть return 1
		exit 1
	fi	
}

build_debug_version() {
	cd sources/Predator-prey
	cloc --version
	cloc --by-file --xml --out=./cloc_result *
	qmake --version
	qmake "QMAKE_CXXFLAGS+=-fprofile-arcs -ftest-coverage -fPIC -O0 -g --coverage" "LIBS+=-lgcov"
	if [ -e "Makefile" ]; then
		make --version
		make
		tests/tst_modeltest -xml -o test_results || true
		cppcheck --version
		cppcheck --enable=all -v  --xml  * 2> cppcheck_result
		gcovr --version
		gcovr -r . --xml --exclude='tst*' -o gcovr_result
		
		valgrind --version
		valgrind --leak-check=full --xml=yes --xml-file=/opt/tomcat/.jenkins/jobs/Predator-prey/workspace/tst_modeltest.%p.result /opt/tomcat/.jenkins/jobs/Predator-prey/workspace/sources/Predator-prey/tests/tst_modeltest || true
		
        #todo вынести cd из ветви условия
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Build debug version failure!"
		#todo использоватть return 1
		exit 1
	fi
}

make_report() {
	cd report
		if [ -e "configfile" ]; then
			doxygen --version
			doxygen configfile
		else
			echo "Doxygen failed"
			echo "configfile does not exist"
		fi
	cd latex
	if [ -e "Makefile" ]; then
		make --version
		make
		#todo вынести cd из ветви условия
		cd ../..
	else
		echo "Makefile does not exist"
		echo "Report failure!"
		#todo вынести cd из ветви условия
		cd ../..
		#todo использоватть return 1
		exit 1
	fi
}

zip_files() {
	if [ -z ${JOB_NAME} ] || [ -z ${BUILD_NUMBER}]; then
		echo "Vars JOB_NAME/BUILD_NUMBER are unset"
		echo "Zip failure!"
		exit 1
	fi

	TITLE="${JOB_NAME}${BUILD_NUMBER}"
	mkdir "$TITLE"

	if [ -e "sources/Predator-prey/consoleApp/consoleApp" ]; then
		cp sources/Predator-prey/consoleApp/consoleApp $TITLE/Predator-prey${BUILD_NUMBER}
		if [ -e "report/Predator-prey.pdf" ]; then
			cp report/Predator.pdf $TITLE/Predator-prey${BUILD_NUMBER}.pdf
		fi
		if [ -e "report/latex/refman.pdf" ]; then
			cp report/latex/refman.pdf $TITLE/Predator-preyDoxygen${BUILD_NUMBER}.pdf
		fi
		zip --version
		zip $TITLE.zip $TITLE/*
	else
		echo "ConsoleApp does not exist"
		echo "Zip failure!"
		#todo использоватть return 1
		exit 1
	fi

}

clean() {
	git clean -f -e *.zip
}
