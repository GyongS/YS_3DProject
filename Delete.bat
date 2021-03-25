rmdir /s /q "ipch"
rmdir /s /q "Debug"
rmdir /s /q "Release"

rmdir /s /q .\ipch
rmdir /s /q .\Log\Client\Debug\x86\
rmdir /s /q .\Log\Editor\Debug\x86\
rmdir /s /q .\Log\Engine\Debug\x86\


del /f /q .\Bin\Client\Debug\x86\Client.exe
del /f /q .\Bin\Client\Debug\x86\Client.ilk
del /f /q .\Bin\Client\Debug\x86\Client.pdb
del /f /q SR_BaseEngine.VC.db
