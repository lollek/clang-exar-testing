#include "LocalVisitor.h"

using namespace clang;
using namespace exar::lower;

bool LocalVisitor::VisitCXXRecordDecl(CXXRecordDecl* decl) {
  RunLowerCaseChecker(decl);
  return true;
}


void LocalVisitor::SetContext(ASTContext* new_context) {
  context = new_context;
}

void LocalVisitor::RunLowerCaseChecker(CXXRecordDecl* decl) {
  StringRef name = decl->getName();
  if (islower(name[0])) {
    DiagnosticsEngine& engine = context->getDiagnostics();
    unsigned id = engine.getCustomDiagID(DiagnosticsEngine::Warning, "Class name should not start with a lower case letter");
    SourceLocation src = decl->getLocation();
    engine.Report(src, id);
  }
}


