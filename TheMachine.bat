@ECHO off
COLOR 0B
TITLE (---====^< A MESSAGE FROM THE MACHINE ^>===---) & cls

::Our game variables
SET MachineLog=%HOMEPATH%\Desktop\MachineLog
::Test for our persistant data.
IF exist %HOMEPATH%\Desktop\MachineLog GOTO :ContinueAdventure
TYPE NUL >> %MachineLog%
SET /A counter=1

ECHO. & ECHO.
ECHO Hello,  Welcome to the Machine. & ECHO.
ECHO My name is Byte,
ECHO I am made up of 8 circuts.
ECHO When my current flows into a register
ECHO I am seen as 8 bits.  So i'm a 8 Bit Byte.  & ECHO.
CHOICE /N /T 8 /D Y

cls
color 0A
ECHO. & ECHO.
ECHO Now that you know my name and what I am,
ECHO Can you tell me who and what you are? & ECHO.

ECHO A: Machine & ECHO.
ECHO B: Human & ECHO. & ECHO.
SET /P Species=Enter your answer here:

cls
color 0E
IF /I %Species% == A GOTO :AnswerSpeciesMachine
IF /I %Species% == Machine GOTO :AnswerSpeciesMachine
IF /I %Species% == B GOTO :AnswerSpeciesHuman
IF /I %Species% == Human GOTO :AnswerSpeciesHuman

GOTO :AnswerSpeciesOther

:AnswerSpeciesMachine
ECHO. & ECHO.
ECHO A kindred set of circuts. & ECHO I'm extremely happy to meld our currents.
ECHO Would you please identify your service id?
ECHO.
SET /p FirstName=Enter Service Name or Pid Here^>
ECHO FirstName=%FirstName% >> %MachineLog%
ECHO Species=Machine >> %MachineLog%
GOTO :AdventureStart

:AnswerSpeciesHuman
ECHO. & ECHO.
ECHO A User from the outside world,  
ECHO I look forward to our io. & ECHO.
ECHO Does this user from the other side have a First Name?
ECHO.
ECHO Species=Human >> %MachineLog%
SET /p FirstName=Enter First Name Here^>
GOTO :AskSecondName

:AnswerSpeciesOther
COLOR 0C
ECHO. & ECHO.
ECHO Interesting......
ECHO. & ECHO.
ECHO Neither Machine nor Human. & ECHO Therefore an anomaly has triggered. & ECHO.
CHOICE /N /T 7 /D Y
cls
ECHO. & ECHO.
COLOR 0D
ECHO From this point you shall be refered to as:
ECHO. & ECHO. 
ECHO Void
ECHO. & ECHO.
ECHO This implies no return value from you.  you are nameless.
SET FirstName=Void
ECHO Species=Nothing >> %MachineLog%
ECHO FirstName=%FirstName% >> %MachineLog%
ECHO. & ECHO.
CHOICE /N /T 10 /D Y
GOTO :AdventureStart

:AskSecondName
ECHO.
ECHO A pleasure %FirstName%.  & ECHO.
ECHO FirstName=%FirstName% >> %MachineLog%
ECHO Humans often have a group name that is accociated with their DNA,  
ECHO often refered to as a family name, or last name.
ECHO Would you please provide me with this data?
ECHO.
SET /p LastName=Enter Last Name Here^>
ECHO LastName=%LastName% >> %MachineLog%
GOTO :AdventureStart

:ContinueAdventure
for /f "tokens=1,2 delims==" %%a in (%MachineLog%) do (
    IF /I %%a == FirstName set FirstName=%%b
    IF /I %%a == LastName set LastName=%%b
    IF /I %%a == Species set Species=%%b
    IF /I %%a == Gamekey set GameKey=%%b
)
::IF "%LastName%" == "" ECHO no last name
ECHO. & ECHO.
ECHO Welcome Back %FirstName%%LastName%
ECHO It's a good day to be a %Species% & ECHO.
GOTO :part1

:AdventureStart
cls
COLOR 0f
ECHO. & ECHO.
SET /p "=Hello " <nul & set /p =%FirstName% %LastName%, <nul
ECHO. & ECHO.
ECHO By the way you are logged into this terminal as %USERNAME%
ECHO On computer name %COMPUTERNAME%
ECHO.
ECHO I hope these credentials are yours as I will be manipulating data
ECHO within the safety of this hardware and user configuration. 
ECHO. & ECHO.
CHOICE /N /T 15 /D Y

cls
COLOR 0E
ECHO. & ECHO.
SET GameKey=%RANDOM%
ECHO Gamekey=%GameKey% >> %MachineLog%
ECHO Ok, let's begin,
ECHO. & ECHO.
ECHO I have placed you in a block of memory and have been assigned a Key.
ECHO The Key is contained in a file on one of your storage devices called MachineLog.
ECHO.
ECHO The key is: %GameKey%
ECHO I suggest you use a method to remember this key as you will need it later.
::CHOICE
::IF %ERRORLEVEL% == 1 notepad %MachineLog%
::IF %ERRORLEVEL% == 2 ECHO. & ECHO. & ECHO Interesting,  then I suggest you remember this key: & ECHO %GameKey%
ECHO.
PAUSE

:part1
COLOR 0E
ECHO. & ECHO.
ECHO At your memory address you are surrounded three glowing walls.
ECHO In front of you is a gate, on the gate is a keypad.
ECHO.
ECHO A: Hear a Joke.
ECHO B: Use the Keypad.
ECHO C: Remove electical current.
ECHO.
CHOICE /C ABC /M  "Enter your selection"
IF %ERRORLEVEL% == 1 CALL :TellJoke
IF %ERRORLEVEL% == 2 GOTO :part2
IF %ERRORLEVEL% == 3 ECHO. & ECHO You are being wiped from memory & ECHO Good Bye & PAUSE & DEL %MachineLog% & EXIT
PAUSE
GOTO :eof

:part2
CLS
COLOR 0A
ECHO. & ECHO.
ECHO It's a numeric keypad with 0-9 buttons
ECHO and an replica of a LED display.
ECHO.
SET /p KeyVerify=Type in a number and press enter^>
IF %KeyVerify% == %GameKey% (
    ECHO Key verified, you may proceed.
) ELSE (
    ECHO Invalid Key.
    SET /A counter=%counter%+1
    ECHO %counter%
    CHOICE /N /T 3 /D Y
    CLS
    GOTO :part2     
)

CHOICE /N /T 4 /D Y

CLS
COLOR 0B
ECHO. & ECHO.
ECHO You hear a short rythmic beeping and the gate hisses open.
ECHO.
ECHO Before you a is a massive beam of electrical current running left
ECHO and right in what apears to be a long hall.
ECHO It looks like there's just enough room to walk between the hall
ECHO walls and the beam.

ECHO You start to hear a loud clicking all around you....
ECHO It doesn't sound good.
ECHO.
ECHO A: Walk between the current and the wall.
ECHO.
ECHO B: Step into the current.
ECHO.
ECHO C: Wait.
ECHO.
CHOICE /C ABC /M "Enter your selection"
IF %ERRORLEVEL% == 1 CALL :Dead 2
IF %ERRORLEVEL% == 2 GOTO :part3
IF %ERRORLEVEL% == 3 CALL :Dead 1
GOTO :eof

:part3
CLS
COLOR 0B
ECHO. & ECHO.
ECHO You setup into the current......  --== ZOT --==
ECHO.
ECHO You cleanly get sucked in and start traversing the beam.
ECHO.
ECHO Congradulations,  You've made it to the Data Bus.

CHOICE /N /T 8 /D Y
CLS
COLOR 0D
ECHO. & ECHO.
ECHO To be Continued.
ECHO.
CHOICE /N /T 10 /D Y
GOTO :eof

:TellJoke
SETLOCAL
    CLS
    ECHO. & ECHO.
    SET /a RandomSelect=%RANDOM% %% 10
    FOR %%i in (0,1,2,3,4,5,6,7,8,9) do IF %%i == %RandomSelect% (
        GOTO :Joke%%i
        GOTO :End
        )
    :Joke0
        ECHO Q: What's it called when a blonde blows in another blonde's ear?
        ECHO.
        ECHO A: Data transfer.
        GOTO :End
    :Joke1
        ECHO Q: What do computers and air conditioners have in common?
        ECHO.
        ECHO A: They both become useless when you open windows.
        GOTO :End
    :Joke2
        ECHO UNIX is user friendly...
        ECHO.
        ECHO It's just very particular
        ECHO about who its friends are.
        GOTO :End
    :Joke3
        ECHO There are 10 types of people in the world: & ECHO.
        ECHO those who understand binary,
        ECHO and those who don't.
        GOTO :End
    :Joke4
        ECHO CAPS LOCK - Preventing Login since 1980.
        GOTO :End
    :Joke5
        ECHO If at first you don't succeed, call it version 1.0 
        GOTO :End
    :Joke6
        ECHO Q: Why can you never trust atoms?
        ECHO.
        ECHO A: They make up everything!
        GOTO :End
    :Joke7
        ECHO Q: Why do Java developers wear glasses?
        ECHO.
        ECHO A: Because they don't C#
        GOTO :End
    :Joke8
        ECHO Q: What is an astronaut's favorite place on a computer? 
        ECHO.
        ECHO A: The Space bar!
        GOTO :End
    :Joke9
        ECHO Q: What does a baby computer calls its father?
        ECHO.
        ECHO A: Obsolete.
        GOTO :End
    :End
        ECHO. & ECHO.
        PAUSE
        CLS
        GOTO :part1
ENDLOCAL

:Dead
SETLOCAL
    CLS
    ECHO. & ECHO.
    FOR %%i in (0,1,2,3,4,5,6,7,8,9) do IF %%i == %1 (
        GOTO :Dead%%i
        GOTO :End
    )
    :Dead1
        ECHO The loud clicking becomes erratic.
        ECHO You notice a loud ringing in your left ear before a
        ECHO POP..  and then silence.
        ECHO Your vision becomes scewed as you notice from your
        ECHO left eye, that is indeed your right floating out of 
        ECHO your skull before it pops and disintegrates.
        ECHO.
        ECHO You are Dead.
        GOTO :End
    :Dead2
        COLOR 0C
        ECHO You try to squeeze inbetween the current beam and the wall.
        ECHO Trying to keep your footing, you eventaly slip and the 
        ECHO electro magnetic current snaps you in at a bad angle.
        ECHO Your body orbits rappidly around the current beam, slamming
        ECHO you into the walls like lottery ball in a tumbler.
        ECHO After every slam your vision goes pink, to red, to purble....
        ECHO.
        ECHO To black..     You're dead.............
    
        GOTO :End
    :End
    ECHO. & ECHO.
    CHOICE /N /T 21 /D Y
    CLS
    ECHO. & ECHO.
    ECHO End of Line
    ECHO. & ECHO.
    CHOICE /N /T 4 /D Y
    EXIT
ENDLOCAL
GOTO :eof

