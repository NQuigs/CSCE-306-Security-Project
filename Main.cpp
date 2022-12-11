#include "Main.h"


using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)

{

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    PRJSecurityProject::Main form;

    Application::Run(% form);

}
