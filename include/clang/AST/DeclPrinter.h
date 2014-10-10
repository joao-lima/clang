#ifndef LLVM_CLANG_AST_DECLPRINTER_H
#define LLVM_CLANG_AST_DECLPRINTER_H

#include "clang/AST/ASTContext.h"
#include "clang/AST/Attr.h"
#include "clang/AST/Decl.h"
#include "clang/AST/DeclCXX.h"
#include "clang/AST/DeclObjC.h"
#include "clang/AST/DeclVisitor.h"
#include "clang/AST/Expr.h"
#include "clang/AST/ExprCXX.h"
#include "clang/AST/PrettyPrinter.h"
#include "clang/Basic/Module.h"
#include "llvm/Support/raw_ostream.h"

namespace clang {
  class DeclPrinter : public DeclVisitor<DeclPrinter> {
  protected:
    raw_ostream &Out;
    PrintingPolicy Policy;
    unsigned Indentation;
    bool PrintInstantiation;

    raw_ostream& Indent() { return Indent(Indentation); }
    raw_ostream& Indent(unsigned Indentation);
    void ProcessDeclGroup(SmallVectorImpl<Decl*>& Decls);

    void Print(AccessSpecifier AS);

  public:
    DeclPrinter(raw_ostream &Out, const PrintingPolicy &Policy,
                unsigned Indentation = 0, bool PrintInstantiation = false)
      : Out(Out), Policy(Policy), Indentation(Indentation),
        PrintInstantiation(PrintInstantiation) { }

    virtual void VisitDeclContext(DeclContext *DC, bool Indent = true);

    virtual void VisitTranslationUnitDecl(TranslationUnitDecl *D);
    virtual void VisitTypedefDecl(TypedefDecl *D);
    virtual void VisitTypeAliasDecl(TypeAliasDecl *D);
    virtual void VisitEnumDecl(EnumDecl *D);
    virtual void VisitRecordDecl(RecordDecl *D);
    virtual void VisitEnumConstantDecl(EnumConstantDecl *D);
    virtual void VisitEmptyDecl(EmptyDecl *D);
    virtual void VisitFunctionDecl(FunctionDecl *D, bool printBody = true);
    virtual void VisitFriendDecl(FriendDecl *D);
    virtual void VisitFieldDecl(FieldDecl *D);
    virtual void VisitVarDecl(VarDecl *D);
    virtual void VisitLabelDecl(LabelDecl *D);
    virtual void VisitParmVarDecl(ParmVarDecl *D);
    virtual void VisitFileScopeAsmDecl(FileScopeAsmDecl *D);
    virtual void VisitImportDecl(ImportDecl *D);
    virtual void VisitStaticAssertDecl(StaticAssertDecl *D);
    virtual void VisitNamespaceDecl(NamespaceDecl *D);
    virtual void VisitUsingDirectiveDecl(UsingDirectiveDecl *D);
    virtual void VisitNamespaceAliasDecl(NamespaceAliasDecl *D);
    virtual void VisitCXXRecordDecl(CXXRecordDecl *D);
    virtual void VisitLinkageSpecDecl(LinkageSpecDecl *D);
    virtual void VisitTemplateDecl(const TemplateDecl *D);
    virtual void VisitFunctionTemplateDecl(FunctionTemplateDecl *D);
    virtual void VisitClassTemplateDecl(ClassTemplateDecl *D);
    virtual void VisitObjCMethodDecl(ObjCMethodDecl *D);
    virtual void VisitObjCImplementationDecl(ObjCImplementationDecl *D);
    virtual void VisitObjCInterfaceDecl(ObjCInterfaceDecl *D);
    virtual void VisitObjCProtocolDecl(ObjCProtocolDecl *D);
    virtual void VisitObjCCategoryImplDecl(ObjCCategoryImplDecl *D);
    virtual void VisitObjCCategoryDecl(ObjCCategoryDecl *D);
    virtual void VisitObjCCompatibleAliasDecl(ObjCCompatibleAliasDecl *D);
    virtual void VisitObjCPropertyDecl(ObjCPropertyDecl *D);
    virtual void VisitObjCPropertyImplDecl(ObjCPropertyImplDecl *D);
    virtual void VisitUnresolvedUsingTypenameDecl(UnresolvedUsingTypenameDecl *D);
    virtual void VisitUnresolvedUsingValueDecl(UnresolvedUsingValueDecl *D);
    virtual void VisitUsingDecl(UsingDecl *D);
    virtual void VisitUsingShadowDecl(UsingShadowDecl *D);
    virtual void VisitOMPThreadPrivateDecl(OMPThreadPrivateDecl *D);
    virtual void VisitOMPDeclareSimdDecl(OMPDeclareSimdDecl *D);
    virtual void VisitOMPDeclareReductionDecl(OMPDeclareReductionDecl *D);
    virtual void VisitOMPDeclareTargetDecl(OMPDeclareTargetDecl *D);

    virtual void PrintTemplateParameters(const TemplateParameterList *Params,
                                         const TemplateArgumentList *Args = 0);
    virtual void prettyPrintAttributes(Decl *D);
  };
}

#endif
