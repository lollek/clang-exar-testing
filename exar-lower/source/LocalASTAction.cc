#include "LocalASTAction.h"

using namespace std;
using namespace clang;
using namespace exar::lower;

ASTConsumer* LocalASTAction::CreateASTConsumer(CompilerInstance &CI, StringRef) {
  return new LocalConsumer();
}

bool LocalASTAction::ParseArgs(CompilerInstance const& CI, vector<string> const& args) {
  return true;
}

