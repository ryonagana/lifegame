##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=lifegame
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/archdark/projetos/cpp/lifegame
ProjectPath            :=/home/archdark/projetos/cpp/lifegame/lifegame
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/lifegame
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Nicholas Oliveira
Date                   :=24/12/23
CodeLitePath           :=/home/archdark/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/g++-13
SharedObjectLinkerName :=/usr/bin/g++-13 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/home/archdark/projetos/cpp/lifegame/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)allegro $(LibrarySwitch)allegro_audio $(LibrarySwitch)allegro_acodec $(LibrarySwitch)allegro_image $(LibrarySwitch)allegro_ttf $(LibrarySwitch)allegro_font $(LibrarySwitch)allegro_primitives $(LibrarySwitch)allegro_dialog $(LibrarySwitch)allegro_physfs 
ArLibs                 :=  "allegro" "allegro_audio" "allegro_acodec" "allegro_image" "allegro_ttf" "allegro_font" "allegro_primitives" "allegro_dialog" "allegro_physfs" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-13
CC       := /usr/bin/gcc-13
CXXFLAGS := -pedantic-errors -g -std=c++14 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/up_gameScreenContext.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_hall.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_informationPanel.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Menu.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_bigTextLabel.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_config.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_button.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_gameScreenContext.cpp$(ObjectSuffix): ../gameScreenContext.cpp $(IntermediateDirectory)/up_gameScreenContext.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/gameScreenContext.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_gameScreenContext.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_gameScreenContext.cpp$(DependSuffix): ../gameScreenContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_gameScreenContext.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_gameScreenContext.cpp$(DependSuffix) -MM ../gameScreenContext.cpp

$(IntermediateDirectory)/up_gameScreenContext.cpp$(PreprocessSuffix): ../gameScreenContext.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_gameScreenContext.cpp$(PreprocessSuffix) ../gameScreenContext.cpp

$(IntermediateDirectory)/up_hall.cpp$(ObjectSuffix): ../hall.cpp $(IntermediateDirectory)/up_hall.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/hall.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_hall.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_hall.cpp$(DependSuffix): ../hall.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_hall.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_hall.cpp$(DependSuffix) -MM ../hall.cpp

$(IntermediateDirectory)/up_hall.cpp$(PreprocessSuffix): ../hall.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_hall.cpp$(PreprocessSuffix) ../hall.cpp

$(IntermediateDirectory)/up_informationPanel.cpp$(ObjectSuffix): ../informationPanel.cpp $(IntermediateDirectory)/up_informationPanel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/informationPanel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_informationPanel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_informationPanel.cpp$(DependSuffix): ../informationPanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_informationPanel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_informationPanel.cpp$(DependSuffix) -MM ../informationPanel.cpp

$(IntermediateDirectory)/up_informationPanel.cpp$(PreprocessSuffix): ../informationPanel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_informationPanel.cpp$(PreprocessSuffix) ../informationPanel.cpp

$(IntermediateDirectory)/up_Menu.cpp$(ObjectSuffix): ../Menu.cpp $(IntermediateDirectory)/up_Menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/Menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Menu.cpp$(DependSuffix): ../Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Menu.cpp$(DependSuffix) -MM ../Menu.cpp

$(IntermediateDirectory)/up_Menu.cpp$(PreprocessSuffix): ../Menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Menu.cpp$(PreprocessSuffix) ../Menu.cpp

$(IntermediateDirectory)/up_bigTextLabel.cpp$(ObjectSuffix): ../bigTextLabel.cpp $(IntermediateDirectory)/up_bigTextLabel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/bigTextLabel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_bigTextLabel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_bigTextLabel.cpp$(DependSuffix): ../bigTextLabel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_bigTextLabel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_bigTextLabel.cpp$(DependSuffix) -MM ../bigTextLabel.cpp

$(IntermediateDirectory)/up_bigTextLabel.cpp$(PreprocessSuffix): ../bigTextLabel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_bigTextLabel.cpp$(PreprocessSuffix) ../bigTextLabel.cpp

$(IntermediateDirectory)/up_config.cpp$(ObjectSuffix): ../config.cpp $(IntermediateDirectory)/up_config.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/config.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_config.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_config.cpp$(DependSuffix): ../config.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_config.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_config.cpp$(DependSuffix) -MM ../config.cpp

$(IntermediateDirectory)/up_config.cpp$(PreprocessSuffix): ../config.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_config.cpp$(PreprocessSuffix) ../config.cpp

$(IntermediateDirectory)/up_main.cpp$(ObjectSuffix): ../main.cpp $(IntermediateDirectory)/up_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_main.cpp$(DependSuffix): ../main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_main.cpp$(DependSuffix) -MM ../main.cpp

$(IntermediateDirectory)/up_main.cpp$(PreprocessSuffix): ../main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_main.cpp$(PreprocessSuffix) ../main.cpp

$(IntermediateDirectory)/up_button.cpp$(ObjectSuffix): ../button.cpp $(IntermediateDirectory)/up_button.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/archdark/projetos/cpp/lifegame/button.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_button.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_button.cpp$(DependSuffix): ../button.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_button.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_button.cpp$(DependSuffix) -MM ../button.cpp

$(IntermediateDirectory)/up_button.cpp$(PreprocessSuffix): ../button.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_button.cpp$(PreprocessSuffix) ../button.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


