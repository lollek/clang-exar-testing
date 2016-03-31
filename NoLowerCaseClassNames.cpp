#include <iostream>

#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Sema/Sema.h"
#include "llvm/Support/raw_ostream.h"

using namespace std;
using namespace clang;

namespace {

class LocalConsumer : public ASTConsumer {
public:
};

class LocalASTAction : public PluginASTAction {
public:
  unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, llvm::StringRef) override {
    return llvm::make_unique<LocalConsumer>();
  }

  bool ParseArgs(CompilerInstance const& CI, vector<string> const& args) override {
    return true;
  }
};

class LocalVisitor : public RecursiveASTVisitor<LocalVisitor> {
public:
  bool VisitCXXRecordDecl(CXXRecordDecl* decl) {
    cout << decl->getNameAsString() << endl;
    return true;
  }
};

} // anonymous namespace

static FrontendPluginRegistry::Add<LocalASTAction>
X("exar-lower", "Checks for class names that start with lowercase");
