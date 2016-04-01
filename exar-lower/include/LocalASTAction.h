#include <clang/AST/AST.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/CompilerInstance.h>

#include "LocalConsumer.h"

namespace exar {
namespace lower {

class LocalASTAction : public clang::PluginASTAction {
public:
  clang::ASTConsumer* CreateASTConsumer(clang::CompilerInstance &CI, clang::StringRef) override;
  bool ParseArgs(clang::CompilerInstance const& CI, std::vector<std::string> const& args) override;
};

} //namespace lower
} //namespace exar
