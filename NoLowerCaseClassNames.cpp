#include <cctype>

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

class LocalVisitor : public RecursiveASTVisitor<LocalVisitor> {
public:
  bool VisitCXXRecordDecl(CXXRecordDecl* decl) {
    RunLowerCaseChecker(decl);
    return true;
  }

  void SetContext(ASTContext* new_context) {
    context = new_context;
  }

  void RunLowerCaseChecker(CXXRecordDecl* decl) {
    StringRef name = decl->getName();
    if (islower(name[0])) {
      DiagnosticsEngine& engine = context->getDiagnostics();
      unsigned id = engine.getCustomDiagID(DiagnosticsEngine::Warning, "Class name should not start with a lower case letter");
      SourceLocation src = decl->getLocation();
      engine.Report(src, id);
    }
  }

private:
  ASTContext* context;
};

class LocalConsumer : public ASTConsumer {
public:
  void HandleTranslationUnit(ASTContext& context) {
    visitor.SetContext(&context);
    visitor.TraverseDecl(context.getTranslationUnitDecl());
  }

private:
  LocalVisitor visitor;
};

class LocalASTAction : public PluginASTAction {
public:
  ASTConsumer* CreateASTConsumer(CompilerInstance &CI, StringRef) override {
    return new LocalConsumer();
  }

  bool ParseArgs(CompilerInstance const& CI, vector<string> const& args) override {
    return true;
  }
};
} // anonymous namespace

static FrontendPluginRegistry::Add<LocalASTAction>
X("exar-lower", "Checks for class names that start with lowercase");
