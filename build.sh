cd source
g++ main.cpp command_parser.cpp -I . -o memo -g -std=c++11
cd ../
mkdir out
mv source/memo out/
echo "done"
