india: debug_india optimize_india

debug_india: indian_bank.cpp compound.cpp reverseCompound.cpp
	g++ -Wall -g indian_bank.cpp compound.cpp reverseCompound.cpp -o indian_bank

optimize_india: indian_bank.cpp compound.cpp reverseCompound.cpp
	g++ -O2 indian_bank.cpp compound.cpp reverseCompound.cpp -o indian_bank_optimised

spain: debug_spain optimize_spain

debug_spain: spain_bank.cpp 
	g++ -Wall -g spain_bank.cpp -o spain_bank

optimize_spain: spain_bank.cpp
	g++ -O2 spain_bank.cpp -o spain_bank_optimised	

clean:
	del indian_bank.exe indian_bank_optimised.exe spain_bank.exe spain_bank_optimised.exe
