#include "CustomLoggerAdapter.h"
#include "MediaGaps/IO/SourceSharedPtr.h"
#include "MediaGaps/IO/FileSource.h"
#include "AribToSRTProgramListenerProvider.h"
#include "MediaGaps/Ts/Demux/TSParser.h"
#include <Windows.h>

#include <iostream>
#include <iomanip>
#include <codecvt>
#include <locale>


using namespace MediaGaps::Ts::Demux;
using namespace MediaGaps::Ts;
using namespace MediaGaps::IO;
using namespace MediaGaps::Media;
using namespace MediaGaps;

void program_usage(const char* programName)
{
	std::cout << "Invalid program usage. Use program as:" << std::endl << std::endl;
	std::cout << programName << " <input_video> <output_dir> " << std::endl << std::endl;
}

std::wstring toWString(const std::string value)
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(value);
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		program_usage(argv[0]);
		return -1;
	}

	try
	{
		const std::wstring inputVideo = toWString(argv[1]);
		const std::wstring outputDir = toWString(argv[2]);

		std::cout << "Starting demo." << std::endl;

		// Start receiving  internal logs from the API
		MOVCreator::CustomLoggerAdapter customLoggerAdapter;

		const SourceSharedPtr source(new FileSource(inputVideo.c_str()));

		AribToSRTProgramListenerProvider aribToSrtProgramListenerProvider(outputDir.c_str());

		TSParser tsParser(source, aribToSrtProgramListenerProvider);

		tsParser.Start();

		while (tsParser.GetState() != IStateProvider::State_Aborted && tsParser.GetState() != IStateProvider
			::State_Finished && tsParser.GetState() != IStateProvider::State_Failed)
		{
			std::cout << "--> API log: " << std::fixed << std::setprecision(2) << tsParser.GetLoadedPercentage() << "% loaded" << std::endl;
			Sleep(2000);
		}

		// Check de final result
		if (tsParser.GetState() == IStateProvider::State_Finished)
		{
			std::cout << "Success while generating srt file" << std::endl;
		}
		else
		{
			std::cout << "Failed to generated srt file with message; " << tsParser.GetErrorMsg() << std::endl;
		}
	}
	catch (const Exception& ex)
	{
		std::cout << "Error while processing:" << ex.GetMGExceptionMessage() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error while processing:" << std::endl;
	}

	std::cout << "Leaving demo." << std::endl;
}
