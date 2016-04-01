#include "clang/AST/AST.h"
#include "clang/AST/RecursiveASTVisitor.h"

namespace exar {
namespace lower {

class LocalVisitor : public clang::RecursiveASTVisitor<LocalVisitor> {
public:
  bool VisitCXXRecordDecl(clang::CXXRecordDecl* decl);
  void SetContext(clang::ASTContext* new_context);
  void RunLowerCaseChecker(clang::CXXRecordDecl* decl);

private:
  clang::ASTContext* context;
};

} //namespace lower
} //namespace exar
