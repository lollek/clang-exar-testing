#include "LocalConsumer.h"

using namespace clang;
using namespace exar::lower;

void LocalConsumer::HandleTranslationUnit(ASTContext& context) {
  visitor.SetContext(&context);
  visitor.TraverseDecl(context.getTranslationUnitDecl());
}


