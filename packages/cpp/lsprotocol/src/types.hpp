// Auto-generated from LSP JSON schema.
#pragma once

#include <string>
#include <vector>
#include <optional>
#include <variant>
#include <glaze/glaze.hpp>
#include <unordered_map>

static constexpr char ascill_toupper(char c) noexcept {
    return (c >= 'a' && c <= 'z') ? static_cast<char>(c - 'a' + 'A') : c;
}

static constexpr std::string to_camel_case(std::string_view sv) {
    std::string out;
    out.reserve(sv.size());
    bool upper_next = false;
    for (size_t i = 0; i < sv.size(); ++i) {
        char c = sv[i];
        if (c == '_' && i + 1 < sv.size()) {
            upper_next = true;
        }
        else {
            if (upper_next) {
                out.push_back(ascill_toupper(c));
                upper_next = false;
            }
            else {
                out.push_back(c);
            }
        }
    }
    return out;
}

// The definition of a symbol represented as one or many {@link Location locations}.
// For most programming languages there is only one location at which a symbol is
// defined.
// 
// Servers should prefer returning `DefinitionLink` over `Definition` if supported
// by the client.
using Definition = std::variant<Location, std::vector<Location>>;

// Information about where a symbol is defined.
// 
// Provides additional metadata over normal {@link Location location} definitions, including the range of
// the defining symbol
using DefinitionLink = LocationLink;

// LSP arrays.
// @since 3.17.0
using LSPArray = std::vector<LSPAny>;

// The LSP any type.
// Please note that strictly speaking a property with the value `undefined`
// can't be converted into JSON preserving the property name. However for
// convenience it is allowed and assumed that all these properties are
// optional as well.
// @since 3.17.0
using LSPAny = std::variant<LSPObject, LSPArray, std::string, int, unsigned int, double, bool, std::nullptr_t>;

// The declaration of a symbol representation as one or many {@link Location locations}.
using Declaration = std::variant<Location, std::vector<Location>>;

// Information about where a symbol is declared.
// 
// Provides additional metadata over normal {@link Location location} declarations, including the range of
// the declaring symbol.
// 
// Servers should prefer returning `DeclarationLink` over `Declaration` if supported
// by the client.
using DeclarationLink = LocationLink;

// Inline value information can be provided by different means:
// - directly as a text value (class InlineValueText).
// - as a name to use for a variable lookup (class InlineValueVariableLookup)
// - as an evaluatable expression (class InlineValueEvaluatableExpression)
// The InlineValue types combines all inline value types into one type.
// 
// @since 3.17.0
using InlineValue = std::variant<InlineValueText, InlineValueVariableLookup, InlineValueEvaluatableExpression>;

// The result of a document diagnostic pull request. A report can
// either be a full report containing all diagnostics for the
// requested document or an unchanged report indicating that nothing
// has changed in terms of diagnostics in comparison to the last
// pull request.
// 
// @since 3.17.0
using DocumentDiagnosticReport = std::variant<RelatedFullDocumentDiagnosticReport, RelatedUnchangedDocumentDiagnosticReport>;

using PrepareRenameResult = std::variant<Range, PrepareRenamePlaceholder, PrepareRenameDefaultBehavior>;

// A document selector is the combination of one or many document filters.
// 
// @sample `let sel:DocumentSelector = [{ language: 'typescript' }, { language: 'json', pattern: '**∕tsconfig.json' }]`;
// 
// The use of a string as a document filter is deprecated @since 3.16.0.
using DocumentSelector = std::vector<DocumentFilter>;

using ProgressToken = std::variant<int, std::string>;

// An identifier to refer to a change annotation stored with a workspace edit.
using ChangeAnnotationIdentifier = std::string;

// A workspace diagnostic document report.
// 
// @since 3.17.0
using WorkspaceDocumentDiagnosticReport = std::variant<WorkspaceFullDocumentDiagnosticReport, WorkspaceUnchangedDocumentDiagnosticReport>;

// An event describing a change to a text document. If only a text is provided
// it is considered to be the full content of the document.
using TextDocumentContentChangeEvent = std::variant<TextDocumentContentChangePartial, TextDocumentContentChangeWholeDocument>;

// MarkedString can be used to render human readable text. It is either a markdown string
// or a code-block that provides a language and a code snippet. The language identifier
// is semantically equal to the optional language identifier in fenced code blocks in GitHub
// issues. See https://help.github.com/articles/creating-and-highlighting-code-blocks/#syntax-highlighting
// 
// The pair of a language and a value is an equivalent to markdown:
// ```${language}
// ${value}
// ```
// 
// Note that markdown strings will be sanitized - that means html will be escaped.
// @deprecated use MarkupContent instead.
using MarkedString = std::variant<std::string, MarkedStringWithLanguage>;

// A document filter describes a top level text document or
// a notebook cell document.
// 
// @since 3.17.0 - support for NotebookCellTextDocumentFilter.
using DocumentFilter = std::variant<TextDocumentFilter, NotebookCellTextDocumentFilter>;

// LSP object definition.
// @since 3.17.0
using LSPObject = std::unordered_map<std::string, LSPAny>;

// The glob pattern. Either a string pattern or a relative pattern.
// 
// @since 3.17.0
using GlobPattern = std::variant<Pattern, RelativePattern>;

// A document filter denotes a document by different properties like
// the {@link TextDocument.languageId language}, the {@link Uri.scheme scheme} of
// its resource, or a glob-pattern that is applied to the {@link TextDocument.fileName path}.
// 
// Glob patterns can have the following syntax:
// - `*` to match one or more characters in a path segment
// - `?` to match on one character in a path segment
// - `**` to match any number of path segments, including none
// - `{}` to group sub patterns into an OR expression. (e.g. `**​/*.{ts,js}` matches all TypeScript and JavaScript files)
// - `[]` to declare a range of characters to match in a path segment (e.g., `example.[0-9]` to match on `example.0`, `example.1`, …)
// - `[!...]` to negate a range of characters to match in a path segment (e.g., `example.[!0-9]` to match on `example.a`, `example.b`, but not `example.0`)
// 
// @sample A language filter that applies to typescript files on disk: `{ language: 'typescript', scheme: 'file' }`
// @sample A language filter that applies to all package.json paths: `{ language: 'json', pattern: '**package.json' }`
// 
// @since 3.17.0
using TextDocumentFilter = std::variant<TextDocumentFilterLanguage, TextDocumentFilterScheme, TextDocumentFilterPattern>;

// A notebook document filter denotes a notebook document by
// different properties. The properties will be match
// against the notebook's URI (same as with documents)
// 
// @since 3.17.0
using NotebookDocumentFilter = std::variant<NotebookDocumentFilterNotebookType, NotebookDocumentFilterScheme, NotebookDocumentFilterPattern>;

// The glob pattern to watch relative to the base path. Glob patterns can have the following syntax:
// - `*` to match one or more characters in a path segment
// - `?` to match on one character in a path segment
// - `**` to match any number of path segments, including none
// - `{}` to group conditions (e.g. `**​/*.{ts,js}` matches all TypeScript and JavaScript files)
// - `[]` to declare a range of characters to match in a path segment (e.g., `example.[0-9]` to match on `example.0`, `example.1`, …)
// - `[!...]` to negate a range of characters to match in a path segment (e.g., `example.[!0-9]` to match on `example.a`, `example.b`, but not `example.0`)
// 
// @since 3.17.0
using Pattern = std::string;

using RegularExpressionEngineKind = std::string;

// A set of predefined token types. This set is not fixed
// an clients can specify additional token types via the
// corresponding client capabilities.
// 
// @since 3.16.0
enum class SemanticTokenTypes
{
    Class,
    Comment,
    // @since 3.17.0
    Decorator,
    Enum,
    EnumMember,
    Event,
    Function,
    Interface,
    Keyword,
    // @since 3.18.0
    Label,
    Macro,
    Method,
    Modifier,
    Namespace,
    Number,
    Operator,
    Parameter,
    Property,
    Regexp,
    String,
    Struct,
    // Represents a generic type. Acts as a fallback for types which can't be mapped to
    // a specific type like class or enum.
    Type,
    TypeParameter,
    Variable,
};

template <>
struct glz::meta<SemanticTokenTypes> {
    using enum SemanticTokenTypes;
    static constexpr auto value = glz::enumerate(
        "class", SemanticTokenTypes::Class,
        "comment", SemanticTokenTypes::Comment,
        "decorator", SemanticTokenTypes::Decorator,
        "enum", SemanticTokenTypes::Enum,
        "enumMember", SemanticTokenTypes::EnumMember,
        "event", SemanticTokenTypes::Event,
        "function", SemanticTokenTypes::Function,
        "interface", SemanticTokenTypes::Interface,
        "keyword", SemanticTokenTypes::Keyword,
        "label", SemanticTokenTypes::Label,
        "macro", SemanticTokenTypes::Macro,
        "method", SemanticTokenTypes::Method,
        "modifier", SemanticTokenTypes::Modifier,
        "namespace", SemanticTokenTypes::Namespace,
        "number", SemanticTokenTypes::Number,
        "operator", SemanticTokenTypes::Operator,
        "parameter", SemanticTokenTypes::Parameter,
        "property", SemanticTokenTypes::Property,
        "regexp", SemanticTokenTypes::Regexp,
        "string", SemanticTokenTypes::String,
        "struct", SemanticTokenTypes::Struct,
        "type", SemanticTokenTypes::Type,
        "typeParameter", SemanticTokenTypes::TypeParameter,
        "variable", SemanticTokenTypes::Variable
    );
};

// A set of predefined token modifiers. This set is not fixed
// an clients can specify additional token types via the
// corresponding client capabilities.
// 
// @since 3.16.0
enum class SemanticTokenModifiers
{
    Abstract,
    Async,
    Declaration,
    DefaultLibrary,
    Definition,
    Deprecated,
    Documentation,
    Modification,
    Readonly,
    Static,
};

template <>
struct glz::meta<SemanticTokenModifiers> {
    using enum SemanticTokenModifiers;
    static constexpr auto value = glz::enumerate(
        "abstract", SemanticTokenModifiers::Abstract,
        "async", SemanticTokenModifiers::Async,
        "declaration", SemanticTokenModifiers::Declaration,
        "defaultLibrary", SemanticTokenModifiers::DefaultLibrary,
        "definition", SemanticTokenModifiers::Definition,
        "deprecated", SemanticTokenModifiers::Deprecated,
        "documentation", SemanticTokenModifiers::Documentation,
        "modification", SemanticTokenModifiers::Modification,
        "readonly", SemanticTokenModifiers::Readonly,
        "static", SemanticTokenModifiers::Static
    );
};

// The document diagnostic report kinds.
// 
// @since 3.17.0
enum class DocumentDiagnosticReportKind
{
    // A diagnostic report with a full
    // set of problems.
    Full,
    // A report indicating that the last
    // returned report is still accurate.
    Unchanged,
};

template <>
struct glz::meta<DocumentDiagnosticReportKind> {
    using enum DocumentDiagnosticReportKind;
    static constexpr auto value = glz::enumerate(
        "full", DocumentDiagnosticReportKind::Full,
        "unchanged", DocumentDiagnosticReportKind::Unchanged
    );
};

// Predefined error codes.
enum class ErrorCodes
{
    InternalError = -32603,
    InvalidParams = -32602,
    InvalidRequest = -32600,
    MethodNotFound = -32601,
    ParseError = -32700,
    // Error code indicating that a server received a notification or
    // request before the server has received the `initialize` request.
    ServerNotInitialized = -32002,
    UnknownErrorCode = -32001,
};

enum class LSPErrorCodes
{
    // The server detected that the content of a document got
    // modified outside normal conditions. A server should
    // NOT send this error code if it detects a content change
    // in it unprocessed messages. The result even computed
    // on an older state might still be useful for the client.
    // 
    // If a client decides that a result is not of any use anymore
    // the client should cancel the request.
    ContentModified = -32801,
    // The client has canceled a request and a server has detected
    // the cancel.
    RequestCancelled = -32800,
    // A request failed but it was syntactically correct, e.g the
    // method name was known and the parameters were valid. The error
    // message should contain human readable information about why
    // the request failed.
    // 
    // @since 3.17.0
    RequestFailed = -32803,
    // The server cancelled the request. This error code should
    // only be used for requests that explicitly support being
    // server cancellable.
    // 
    // @since 3.17.0
    ServerCancelled = -32802,
};

// A set of predefined range kinds.
enum class FoldingRangeKind
{
    // Folding range for a comment
    Comment,
    // Folding range for an import or include
    Imports,
    // Folding range for a region (e.g. `#region`)
    Region,
};

template <>
struct glz::meta<FoldingRangeKind> {
    using enum FoldingRangeKind;
    static constexpr auto value = glz::enumerate(
        "comment", FoldingRangeKind::Comment,
        "imports", FoldingRangeKind::Imports,
        "region", FoldingRangeKind::Region
    );
};

// A symbol kind.
enum class SymbolKind
{
    Array = 18,
    Boolean = 17,
    Class = 5,
    Constant = 14,
    Constructor = 9,
    Enum = 10,
    EnumMember = 22,
    Event = 24,
    Field = 8,
    File = 1,
    Function = 12,
    Interface = 11,
    Key = 20,
    Method = 6,
    Module = 2,
    Namespace = 3,
    Null = 21,
    Number = 16,
    Object = 19,
    Operator = 25,
    Package = 4,
    Property = 7,
    String = 15,
    Struct = 23,
    TypeParameter = 26,
    Variable = 13,
};

// Symbol tags are extra annotations that tweak the rendering of a symbol.
// 
// @since 3.16
enum class SymbolTag
{
    // Render a symbol as obsolete, usually using a strike-out.
    Deprecated = 1,
};

// Moniker uniqueness level to define scope of the moniker.
// 
// @since 3.16.0
enum class UniquenessLevel
{
    // The moniker is only unique inside a document
    Document,
    // The moniker is globally unique
    Global,
    // The moniker is unique inside the group to which a project belongs
    Group,
    // The moniker is unique inside a project for which a dump got created
    Project,
    // The moniker is unique inside the moniker scheme.
    Scheme,
};

template <>
struct glz::meta<UniquenessLevel> {
    using enum UniquenessLevel;
    static constexpr auto value = glz::enumerate(
        "document", UniquenessLevel::Document,
        "global", UniquenessLevel::Global,
        "group", UniquenessLevel::Group,
        "project", UniquenessLevel::Project,
        "scheme", UniquenessLevel::Scheme
    );
};

// The moniker kind.
// 
// @since 3.16.0
enum class MonikerKind
{
    // The moniker represents a symbol that is exported from a project
    Export,
    // The moniker represent a symbol that is imported into a project
    Import,
    // The moniker represents a symbol that is local to a project (e.g. a local
    // variable of a function, a class not visible outside the project, ...)
    Local,
};

template <>
struct glz::meta<MonikerKind> {
    using enum MonikerKind;
    static constexpr auto value = glz::enumerate(
        "export", MonikerKind::Export,
        "import", MonikerKind::Import,
        "local", MonikerKind::Local
    );
};

// Inlay hint kinds.
// 
// @since 3.17.0
enum class InlayHintKind
{
    // An inlay hint that is for a parameter.
    Parameter = 2,
    // An inlay hint that for a type annotation.
    Type = 1,
};

// The message type
enum class MessageType
{
    // A debug message.
    // 
    // @since 3.18.0
    // @proposed
    Debug = 5,
    // An error message.
    Error = 1,
    // An information message.
    Info = 3,
    // A log message.
    Log = 4,
    // A warning message.
    Warning = 2,
};

// Defines how the host (editor) should sync
// document changes to the language server.
enum class TextDocumentSyncKind
{
    // Documents are synced by always sending the full content
    // of the document.
    Full = 1,
    // Documents are synced by sending the full content on open.
    // After that only incremental updates to the document are
    // send.
    Incremental = 2,
    // Documents should not be synced at all.
    None = 0,
};

// Represents reasons why a text document is saved.
enum class TextDocumentSaveReason
{
    // Automatic after a delay.
    AfterDelay = 2,
    // When the editor lost focus.
    FocusOut = 3,
    // Manually triggered, e.g. by the user pressing save, by starting debugging,
    // or by an API call.
    Manual = 1,
};

// The kind of a completion entry.
enum class CompletionItemKind
{
    Class = 7,
    Color = 16,
    Constant = 21,
    Constructor = 4,
    Enum = 13,
    EnumMember = 20,
    Event = 23,
    Field = 5,
    File = 17,
    Folder = 19,
    Function = 3,
    Interface = 8,
    Keyword = 14,
    Method = 2,
    Module = 9,
    Operator = 24,
    Property = 10,
    Reference = 18,
    Snippet = 15,
    Struct = 22,
    Text = 1,
    TypeParameter = 25,
    Unit = 11,
    Value = 12,
    Variable = 6,
};

// Completion item tags are extra annotations that tweak the rendering of a completion
// item.
// 
// @since 3.15.0
enum class CompletionItemTag
{
    // Render a completion as obsolete, usually using a strike-out.
    Deprecated = 1,
};

// Defines whether the insert text in a completion item should be interpreted as
// plain text or a snippet.
enum class InsertTextFormat
{
    // The primary text to be inserted is treated as a plain string.
    PlainText = 1,
    // The primary text to be inserted is treated as a snippet.
    // 
    // A snippet can define tab stops and placeholders with `$1`, `$2`
    // and `${3:foo}`. `$0` defines the final tab stop, it defaults to
    // the end of the snippet. Placeholders with equal identifiers are linked,
    // that is typing in one will update others too.
    // 
    // See also: https://microsoft.github.io/language-server-protocol/specifications/specification-current/#snippet_syntax
    Snippet = 2,
};

// How whitespace and indentation is handled during completion
// item insertion.
// 
// @since 3.16.0
enum class InsertTextMode
{
    // The editor adjusts leading whitespace of new lines so that
    // they match the indentation up to the cursor of the line for
    // which the item is accepted.
    // 
    // Consider a line like this: <2tabs><cursor><3tabs>foo. Accepting a
    // multi line completion item is indented using 2 tabs and all
    // following lines inserted will be indented using 2 tabs as well.
    AdjustIndentation = 2,
    // The insertion or replace strings is taken as it is. If the
    // value is multi line the lines below the cursor will be
    // inserted using the indentation defined in the string value.
    // The client will not apply any kind of adjustments to the
    // string.
    AsIs = 1,
};

// A document highlight kind.
enum class DocumentHighlightKind
{
    // Read-access of a symbol, like reading a variable.
    Read = 2,
    // A textual occurrence.
    Text = 1,
    // Write-access of a symbol, like writing to a variable.
    Write = 3,
};

// A set of predefined code action kinds
enum class CodeActionKind
{
    // Empty kind.
    Empty,
    // Base kind for all code actions applying to the entire notebook's scope. CodeActionKinds using
    // this should always begin with `notebook.`
    // 
    // @since 3.18.0
    Notebook,
    // Base kind for quickfix actions: 'quickfix'
    QuickFix,
    // Base kind for refactoring actions: 'refactor'
    Refactor,
    // Base kind for refactoring extraction actions: 'refactor.extract'
    // 
    // Example extract actions:
    // 
    // - Extract method
    // - Extract function
    // - Extract variable
    // - Extract interface from class
    // - ...
    RefactorExtract,
    // Base kind for refactoring inline actions: 'refactor.inline'
    // 
    // Example inline actions:
    // 
    // - Inline function
    // - Inline variable
    // - Inline constant
    // - ...
    RefactorInline,
    // Base kind for refactoring move actions: `refactor.move`
    // 
    // Example move actions:
    // 
    // - Move a function to a new file
    // - Move a property between classes
    // - Move method to base class
    // - ...
    // 
    // @since 3.18.0
    // @proposed
    RefactorMove,
    // Base kind for refactoring rewrite actions: 'refactor.rewrite'
    // 
    // Example rewrite actions:
    // 
    // - Convert JavaScript function to class
    // - Add or remove parameter
    // - Encapsulate field
    // - Make method static
    // - Move method to base class
    // - ...
    RefactorRewrite,
    // Base kind for source actions: `source`
    // 
    // Source code actions apply to the entire file.
    Source,
    // Base kind for auto-fix source actions: `source.fixAll`.
    // 
    // Fix all actions automatically fix errors that have a clear fix that do not require user input.
    // They should not suppress errors or perform unsafe fixes such as generating new types or classes.
    // 
    // @since 3.15.0
    SourceFixAll,
    // Base kind for an organize imports source action: `source.organizeImports`
    SourceOrganizeImports,
};

template <>
struct glz::meta<CodeActionKind> {
    using enum CodeActionKind;
    static constexpr auto value = glz::enumerate(
        "", CodeActionKind::Empty,
        "notebook", CodeActionKind::Notebook,
        "quickfix", CodeActionKind::QuickFix,
        "refactor", CodeActionKind::Refactor,
        "refactor.extract", CodeActionKind::RefactorExtract,
        "refactor.inline", CodeActionKind::RefactorInline,
        "refactor.move", CodeActionKind::RefactorMove,
        "refactor.rewrite", CodeActionKind::RefactorRewrite,
        "source", CodeActionKind::Source,
        "source.fixAll", CodeActionKind::SourceFixAll,
        "source.organizeImports", CodeActionKind::SourceOrganizeImports
    );
};

// Code action tags are extra annotations that tweak the behavior of a code action.
// 
// @since 3.18.0 - proposed
enum class CodeActionTag
{
    // Marks the code action as LLM-generated.
    LlmGenerated = 1,
};

enum class TraceValue
{
    // Trace messages only.
    Messages,
    // Turn tracing off.
    Off,
    // Verbose message tracing.
    Verbose,
};

template <>
struct glz::meta<TraceValue> {
    using enum TraceValue;
    static constexpr auto value = glz::enumerate(
        "messages", TraceValue::Messages,
        "off", TraceValue::Off,
        "verbose", TraceValue::Verbose
    );
};

// Describes the content type that a client supports in various
// result literals like `Hover`, `ParameterInfo` or `CompletionItem`.
// 
// Please note that `MarkupKinds` must not start with a `$`. This kinds
// are reserved for internal usage.
enum class MarkupKind
{
    // Markdown is supported as a content format
    Markdown,
    // Plain text is supported as a content format
    PlainText,
};

template <>
struct glz::meta<MarkupKind> {
    using enum MarkupKind;
    static constexpr auto value = glz::enumerate(
        "markdown", MarkupKind::Markdown,
        "plaintext", MarkupKind::PlainText
    );
};

// Predefined Language kinds
// @since 3.18.0
enum class LanguageKind
{
    Abap,
    BibTeX,
    C,
    Clojure,
    Coffeescript,
    Cpp,
    CSharp,
    Css,
    // @since 3.18.0
    // @proposed
    D,
    Dart,
    // @since 3.18.0
    // @proposed
    Delphi,
    Diff,
    Dockerfile,
    Elixir,
    Erlang,
    FSharp,
    GitCommit,
    GitRebase,
    Go,
    Groovy,
    Handlebars,
    Haskell,
    Html,
    Ini,
    Java,
    JavaScript,
    JavaScriptReact,
    Json,
    LaTeX,
    Less,
    Lua,
    Makefile,
    Markdown,
    ObjectiveC,
    ObjectiveCpp,
    // @since 3.18.0
    // @proposed
    Pascal,
    Perl,
    Perl6,
    Php,
    Powershell,
    Pug,
    Python,
    R,
    Razor,
    Ruby,
    Rust,
    Sass,
    Scala,
    Scss,
    ShaderLab,
    ShellScript,
    Sql,
    Swift,
    TeX,
    TypeScript,
    TypeScriptReact,
    VisualBasic,
    WindowsBat,
    Xml,
    Xsl,
    Yaml,
};

template <>
struct glz::meta<LanguageKind> {
    using enum LanguageKind;
    static constexpr auto value = glz::enumerate(
        "abap", LanguageKind::Abap,
        "bibtex", LanguageKind::BibTeX,
        "c", LanguageKind::C,
        "clojure", LanguageKind::Clojure,
        "coffeescript", LanguageKind::Coffeescript,
        "cpp", LanguageKind::Cpp,
        "csharp", LanguageKind::CSharp,
        "css", LanguageKind::Css,
        "d", LanguageKind::D,
        "dart", LanguageKind::Dart,
        "pascal", LanguageKind::Delphi,
        "diff", LanguageKind::Diff,
        "dockerfile", LanguageKind::Dockerfile,
        "elixir", LanguageKind::Elixir,
        "erlang", LanguageKind::Erlang,
        "fsharp", LanguageKind::FSharp,
        "git-commit", LanguageKind::GitCommit,
        "rebase", LanguageKind::GitRebase,
        "go", LanguageKind::Go,
        "groovy", LanguageKind::Groovy,
        "handlebars", LanguageKind::Handlebars,
        "haskell", LanguageKind::Haskell,
        "html", LanguageKind::Html,
        "ini", LanguageKind::Ini,
        "java", LanguageKind::Java,
        "javascript", LanguageKind::JavaScript,
        "javascriptreact", LanguageKind::JavaScriptReact,
        "json", LanguageKind::Json,
        "latex", LanguageKind::LaTeX,
        "less", LanguageKind::Less,
        "lua", LanguageKind::Lua,
        "makefile", LanguageKind::Makefile,
        "markdown", LanguageKind::Markdown,
        "objective-c", LanguageKind::ObjectiveC,
        "objective-cpp", LanguageKind::ObjectiveCpp,
        "pascal", LanguageKind::Pascal,
        "perl", LanguageKind::Perl,
        "perl6", LanguageKind::Perl6,
        "php", LanguageKind::Php,
        "powershell", LanguageKind::Powershell,
        "jade", LanguageKind::Pug,
        "python", LanguageKind::Python,
        "r", LanguageKind::R,
        "razor", LanguageKind::Razor,
        "ruby", LanguageKind::Ruby,
        "rust", LanguageKind::Rust,
        "sass", LanguageKind::Sass,
        "scala", LanguageKind::Scala,
        "scss", LanguageKind::Scss,
        "shaderlab", LanguageKind::ShaderLab,
        "shellscript", LanguageKind::ShellScript,
        "sql", LanguageKind::Sql,
        "swift", LanguageKind::Swift,
        "tex", LanguageKind::TeX,
        "typescript", LanguageKind::TypeScript,
        "typescriptreact", LanguageKind::TypeScriptReact,
        "vb", LanguageKind::VisualBasic,
        "bat", LanguageKind::WindowsBat,
        "xml", LanguageKind::Xml,
        "xsl", LanguageKind::Xsl,
        "yaml", LanguageKind::Yaml
    );
};

// Describes how an {@link InlineCompletionItemProvider inline completion provider} was triggered.
// 
// @since 3.18.0
// @proposed
enum class InlineCompletionTriggerKind
{
    // Completion was triggered automatically while editing.
    Automatic = 2,
    // Completion was triggered explicitly by a user gesture.
    Invoked = 1,
};

// A set of predefined position encoding kinds.
// 
// @since 3.17.0
enum class PositionEncodingKind
{
    // Character offsets count UTF-16 code units.
    // 
    // This is the default and must always be supported
    // by servers
    Utf16,
    // Character offsets count UTF-32 code units.
    // 
    // Implementation note: these are the same as Unicode codepoints,
    // so this `PositionEncodingKind` may also be used for an
    // encoding-agnostic representation of character offsets.
    Utf32,
    // Character offsets count UTF-8 code units (e.g. bytes).
    Utf8,
};

template <>
struct glz::meta<PositionEncodingKind> {
    using enum PositionEncodingKind;
    static constexpr auto value = glz::enumerate(
        "utf-16", PositionEncodingKind::Utf16,
        "utf-32", PositionEncodingKind::Utf32,
        "utf-8", PositionEncodingKind::Utf8
    );
};

// The file event type
enum class FileChangeType
{
    // The file got changed.
    Changed = 2,
    // The file got created.
    Created = 1,
    // The file got deleted.
    Deleted = 3,
};

enum class WatchKind
{
    // Interested in change events
    Change = 2,
    // Interested in create events.
    Create = 1,
    // Interested in delete events
    Delete = 4,
};

// The diagnostic's severity.
enum class DiagnosticSeverity
{
    // Reports an error.
    Error = 1,
    // Reports a hint.
    Hint = 4,
    // Reports an information.
    Information = 3,
    // Reports a warning.
    Warning = 2,
};

// The diagnostic tags.
// 
// @since 3.15.0
enum class DiagnosticTag
{
    // Deprecated or obsolete code.
    // 
    // Clients are allowed to rendered diagnostics with this tag strike through.
    Deprecated = 2,
    // Unused or unnecessary code.
    // 
    // Clients are allowed to render diagnostics with this tag faded out instead of having
    // an error squiggle.
    Unnecessary = 1,
};

// How a completion was triggered
enum class CompletionTriggerKind
{
    // Completion was triggered by typing an identifier (24x7 code
    // complete), manual invocation (e.g Ctrl+Space) or via API.
    Invoked = 1,
    // Completion was triggered by a trigger character specified by
    // the `triggerCharacters` properties of the `CompletionRegistrationOptions`.
    TriggerCharacter = 2,
    // Completion was re-triggered as current completion list is incomplete
    TriggerForIncompleteCompletions = 3,
};

// Defines how values from a set of defaults and an individual item will be
// merged.
// 
// @since 3.18.0
enum class ApplyKind
{
    // The value from the item will be merged with the default.
    // 
    // The specific rules for mergeing values are defined against each field
    // that supports merging.
    Merge = 2,
    // The value from the individual item (if provided and not `null`) will be
    // used instead of the default.
    Replace = 1,
};

// How a signature help was triggered.
// 
// @since 3.15.0
enum class SignatureHelpTriggerKind
{
    // Signature help was triggered by the cursor moving or by the document content changing.
    ContentChange = 3,
    // Signature help was invoked manually by the user or by a command.
    Invoked = 1,
    // Signature help was triggered by a trigger character.
    TriggerCharacter = 2,
};

// The reason why code actions were requested.
// 
// @since 3.17.0
enum class CodeActionTriggerKind
{
    // Code actions were requested automatically.
    // 
    // This typically happens when current selection in a file changes, but can
    // also be triggered when file content changes.
    Automatic = 2,
    // Code actions were explicitly requested by the user or by an extension.
    Invoked = 1,
};

// A pattern kind describing if a glob pattern matches a file a folder or
// both.
// 
// @since 3.16.0
enum class FileOperationPatternKind
{
    // The pattern matches a file only.
    File,
    // The pattern matches a folder only.
    Folder,
};

template <>
struct glz::meta<FileOperationPatternKind> {
    using enum FileOperationPatternKind;
    static constexpr auto value = glz::enumerate(
        "file", FileOperationPatternKind::File,
        "folder", FileOperationPatternKind::Folder
    );
};

// A notebook cell kind.
// 
// @since 3.17.0
enum class NotebookCellKind
{
    // A code-cell is source code.
    Code = 2,
    // A markup-cell is formatted source that is used for display.
    Markup = 1,
};

enum class ResourceOperationKind
{
    // Supports creating new files and folders.
    Create,
    // Supports deleting existing files and folders.
    Delete,
    // Supports renaming existing files and folders.
    Rename,
};

template <>
struct glz::meta<ResourceOperationKind> {
    using enum ResourceOperationKind;
    static constexpr auto value = glz::enumerate(
        "create", ResourceOperationKind::Create,
        "delete", ResourceOperationKind::Delete,
        "rename", ResourceOperationKind::Rename
    );
};

enum class FailureHandlingKind
{
    // Applying the workspace change is simply aborted if one of the changes provided
    // fails. All operations executed before the failing operation stay executed.
    Abort,
    // If the workspace edit contains only textual file changes they are executed transactional.
    // If resource changes (create, rename or delete file) are part of the change the failure
    // handling strategy is abort.
    TextOnlyTransactional,
    // All operations are executed transactional. That means they either all
    // succeed or no changes at all are applied to the workspace.
    Transactional,
    // The client tries to undo the operations already executed. But there is no
    // guarantee that this is succeeding.
    Undo,
};

template <>
struct glz::meta<FailureHandlingKind> {
    using enum FailureHandlingKind;
    static constexpr auto value = glz::enumerate(
        "abort", FailureHandlingKind::Abort,
        "textOnlyTransactional", FailureHandlingKind::TextOnlyTransactional,
        "transactional", FailureHandlingKind::Transactional,
        "undo", FailureHandlingKind::Undo
    );
};

enum class PrepareSupportDefaultBehavior
{
    // The client's default behavior is to select the identifier
    // according the to language's syntax rule.
    Identifier = 1,
};

enum class TokenFormat
{
    Relative,
};

template <>
struct glz::meta<TokenFormat> {
    using enum TokenFormat;
    static constexpr auto value = glz::enumerate(
        "relative", TokenFormat::Relative
    );
};

struct ImplementationParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<ImplementationParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a location inside a resource, such as a line
// inside a text file.
struct Location
{
    Range range;
    std::string uri;
};

template <>
struct glz::meta<Location> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct ImplementationRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, ImplementationRegistrationOptions> {
    template <auto Opts>
    static void op(const ImplementationRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

struct TypeDefinitionParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<TypeDefinitionParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct TypeDefinitionRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, TypeDefinitionRegistrationOptions> {
    template <auto Opts>
    static void op(const TypeDefinitionRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// A workspace folder inside a client.
struct WorkspaceFolder
{
    // The name of the workspace folder. Used to refer to this
    // workspace folder in the user interface.
    std::string name;
    // The associated URI for this workspace folder.
    std::string uri;
};

template <>
struct glz::meta<WorkspaceFolder> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters of a `workspace/didChangeWorkspaceFolders` notification.
struct DidChangeWorkspaceFoldersParams
{
    // The actual workspace folder change event.
    WorkspaceFoldersChangeEvent event;
};

template <>
struct glz::meta<DidChangeWorkspaceFoldersParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters of a configuration request.
struct ConfigurationParams
{
    std::vector<ConfigurationItem> items;
};

template <>
struct glz::meta<ConfigurationParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Parameters for a {@link DocumentColorRequest}.
struct DocumentColorParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentColorParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a color range from a document.
struct ColorInformation
{
    // The actual color value for this color range.
    Color color;
    // The range in the document where this color appears.
    Range range;
};

template <>
struct glz::meta<ColorInformation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DocumentColorRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DocumentColorRegistrationOptions> {
    template <auto Opts>
    static void op(const DocumentColorRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link ColorPresentationRequest}.
struct ColorPresentationParams
{
    // The color to request presentations for.
    Color color;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The range where the color would be inserted. Serves as a context.
    Range range;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<ColorPresentationParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct ColorPresentation
{
    // An optional array of additional {@link TextEdit text edits} that are applied when
    // selecting this color presentation. Edits must not overlap with the main {@link ColorPresentation.textEdit edit} nor with themselves.
    std::optional<std::vector<TextEdit>> additional_text_edits;
    // The label of this color presentation. It will be shown on the color
    // picker header. By default this is also the text that is inserted when selecting
    // this color presentation.
    std::string label;
    // An {@link TextEdit edit} which is applied to a document when selecting
    // this presentation for the color.  When `falsy` the {@link ColorPresentation.label label}
    // is used.
    std::optional<TextEdit> text_edit;
};

template <>
struct glz::meta<ColorPresentation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkDoneProgressOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<WorkDoneProgressOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// General text document registration options.
struct TextDocumentRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
};

template <>
struct glz::to<glz::JSON, TextDocumentRegistrationOptions> {
    template <auto Opts>
    static void op(const TextDocumentRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link FoldingRangeRequest}.
struct FoldingRangeParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<FoldingRangeParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a folding range. To be valid, start and end line must be bigger than zero and smaller
// than the number of lines in the document. Clients are free to ignore invalid ranges.
struct FoldingRange
{
    // The text that the client should show when the specified range is
    // collapsed. If not defined or not supported by the client, a default
    // will be chosen by the client.
    // 
    // @since 3.17.0
    std::optional<std::string> collapsed_text;
    // The zero-based character offset before the folded range ends. If not defined, defaults to the length of the end line.
    std::optional<unsigned int> end_character;
    // The zero-based end line of the range to fold. The folded area ends with the line's last character.
    // To be valid, the end must be zero or larger and smaller than the number of lines in the document.
    unsigned int end_line;
    // Describes the kind of the folding range such as 'comment' or 'region'. The kind
    // is used to categorize folding ranges and used by commands like 'Fold all comments'.
    // See {@link FoldingRangeKind} for an enumeration of standardized kinds.
    std::optional<FoldingRangeKind> kind;
    // The zero-based character offset from where the folded range starts. If not defined, defaults to the length of the start line.
    std::optional<unsigned int> start_character;
    // The zero-based start line of the range to fold. The folded area starts after the line's last character.
    // To be valid, the end must be zero or larger and smaller than the number of lines in the document.
    unsigned int start_line;
};

template <>
struct glz::meta<FoldingRange> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct FoldingRangeRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, FoldingRangeRegistrationOptions> {
    template <auto Opts>
    static void op(const FoldingRangeRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

struct DeclarationParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DeclarationParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DeclarationRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DeclarationRegistrationOptions> {
    template <auto Opts>
    static void op(const DeclarationRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// A parameter literal used in selection range requests.
struct SelectionRangeParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The positions inside the text document.
    std::vector<Position> positions;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<SelectionRangeParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A selection range represents a part of a selection hierarchy. A selection range
// may have a parent selection range that contains it.
struct SelectionRange
{
    // The parent selection range containing this range. Therefore `parent.range` must contain `this.range`.
    std::optional<SelectionRange> parent;
    // The {@link Range range} of this selection range.
    Range range;
};

template <>
struct glz::meta<SelectionRange> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct SelectionRangeRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, SelectionRangeRegistrationOptions> {
    template <auto Opts>
    static void op(const SelectionRangeRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

struct WorkDoneProgressCreateParams
{
    // The token to be used to report progress.
    ProgressToken token;
};

template <>
struct glz::meta<WorkDoneProgressCreateParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkDoneProgressCancelParams
{
    // The token to be used to report progress.
    ProgressToken token;
};

template <>
struct glz::meta<WorkDoneProgressCancelParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameter of a `textDocument/prepareCallHierarchy` request.
// 
// @since 3.16.0
struct CallHierarchyPrepareParams
{
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<CallHierarchyPrepareParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents programming constructs like functions or constructors in the context
// of call hierarchy.
// 
// @since 3.16.0
struct CallHierarchyItem
{
    // A data entry field that is preserved between a call hierarchy prepare and
    // incoming calls or outgoing calls requests.
    std::optional<LSPAny> data;
    // More detail for this item, e.g. the signature of a function.
    std::optional<std::string> detail;
    // The kind of this item.
    SymbolKind kind;
    // The name of this item.
    std::string name;
    // The range enclosing this symbol not including leading/trailing whitespace but everything else, e.g. comments and code.
    Range range;
    // The range that should be selected and revealed when this symbol is being picked, e.g. the name of a function.
    // Must be contained by the {@link CallHierarchyItem.range `range`}.
    Range selection_range;
    // Tags for this item.
    std::optional<std::vector<SymbolTag>> tags;
    // The resource identifier of this item.
    std::string uri;
};

template <>
struct glz::meta<CallHierarchyItem> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Call hierarchy options used during static or dynamic registration.
// 
// @since 3.16.0
struct CallHierarchyRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, CallHierarchyRegistrationOptions> {
    template <auto Opts>
    static void op(const CallHierarchyRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameter of a `callHierarchy/incomingCalls` request.
// 
// @since 3.16.0
struct CallHierarchyIncomingCallsParams
{
    CallHierarchyItem item;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<CallHierarchyIncomingCallsParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents an incoming call, e.g. a caller of a method or constructor.
// 
// @since 3.16.0
struct CallHierarchyIncomingCall
{
    // The item that makes the call.
    CallHierarchyItem from;
    // The ranges at which the calls appear. This is relative to the caller
    // denoted by {@link CallHierarchyIncomingCall.from `this.from`}.
    std::vector<Range> from_ranges;
};

template <>
struct glz::meta<CallHierarchyIncomingCall> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameter of a `callHierarchy/outgoingCalls` request.
// 
// @since 3.16.0
struct CallHierarchyOutgoingCallsParams
{
    CallHierarchyItem item;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<CallHierarchyOutgoingCallsParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents an outgoing call, e.g. calling a getter from a method or a method from a constructor etc.
// 
// @since 3.16.0
struct CallHierarchyOutgoingCall
{
    // The range at which this item is called. This is the range relative to the caller, e.g the item
    // passed to {@link CallHierarchyItemProvider.provideCallHierarchyOutgoingCalls `provideCallHierarchyOutgoingCalls`}
    // and not {@link CallHierarchyOutgoingCall.to `this.to`}.
    std::vector<Range> from_ranges;
    // The item that is called.
    CallHierarchyItem to;
};

template <>
struct glz::meta<CallHierarchyOutgoingCall> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<SemanticTokensParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokens
{
    // The actual tokens.
    std::vector<unsigned int> data;
    // An optional result id. If provided and clients support delta updating
    // the client will include the result id in the next semantic token request.
    // A server can then instead of computing all semantic tokens again simply
    // send a delta.
    std::optional<std::string> result_id;
};

template <>
struct glz::meta<SemanticTokens> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensPartialResult
{
    std::vector<unsigned int> data;
};

template <>
struct glz::meta<SemanticTokensPartialResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // Server supports providing semantic tokens for a full document.
    std::optional<std::variant<bool, SemanticTokensFullDelta>> full;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    // The legend used by the server
    SemanticTokensLegend legend;
    // Server supports providing semantic tokens for a specific range
    // of a document.
    std::optional<std::variant<bool, LSPObject>> range;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, SemanticTokensRegistrationOptions> {
    template <auto Opts>
    static void op(const SemanticTokensRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "full", v.full,
            "id", v.id,
            "legend", v.legend,
            "range", v.range,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// @since 3.16.0
struct SemanticTokensDeltaParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The result id of a previous response. The result Id can either point to a full response
    // or a delta response depending on what was received last.
    std::string previous_result_id;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<SemanticTokensDeltaParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensDelta
{
    // The semantic token edits to transform a previous result into a new result.
    std::vector<SemanticTokensEdit> edits;
    std::optional<std::string> result_id;
};

template <>
struct glz::meta<SemanticTokensDelta> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensDeltaPartialResult
{
    std::vector<SemanticTokensEdit> edits;
};

template <>
struct glz::meta<SemanticTokensDeltaPartialResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensRangeParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The range the semantic tokens are requested for.
    Range range;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<SemanticTokensRangeParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Params to show a resource in the UI.
// 
// @since 3.16.0
struct ShowDocumentParams
{
    // Indicates to show the resource in an external program.
    // To show, for example, `https://code.visualstudio.com/`
    // in the default WEB browser set `external` to `true`.
    std::optional<bool> external;
    // An optional selection range if the document is a text
    // document. Clients might ignore the property if an
    // external program is started or the file is not a text
    // file.
    std::optional<Range> selection;
    // An optional property to indicate whether the editor
    // showing the document should take focus or not.
    // Clients might ignore this property if an external
    // program is started.
    std::optional<bool> take_focus;
    // The uri to show.
    std::string uri;
};

template <>
struct glz::meta<ShowDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The result of a showDocument request.
// 
// @since 3.16.0
struct ShowDocumentResult
{
    // A boolean indicating if the show was successful.
    bool success;
};

template <>
struct glz::meta<ShowDocumentResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct LinkedEditingRangeParams
{
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<LinkedEditingRangeParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The result of a linked editing range request.
// 
// @since 3.16.0
struct LinkedEditingRanges
{
    // A list of ranges that can be edited together. The ranges must have
    // identical length and contain identical text content. The ranges cannot overlap.
    std::vector<Range> ranges;
    // An optional word pattern (regular expression) that describes valid contents for
    // the given ranges. If no pattern is provided, the client configuration's word
    // pattern will be used.
    std::optional<std::string> word_pattern;
};

template <>
struct glz::meta<LinkedEditingRanges> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct LinkedEditingRangeRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, LinkedEditingRangeRegistrationOptions> {
    template <auto Opts>
    static void op(const LinkedEditingRangeRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters sent in notifications/requests for user-initiated creation of
// files.
// 
// @since 3.16.0
struct CreateFilesParams
{
    // An array of all files/folders created in this operation.
    std::vector<FileCreate> files;
};

template <>
struct glz::meta<CreateFilesParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A workspace edit represents changes to many resources managed in the workspace. The edit
// should either provide `changes` or `documentChanges`. If documentChanges are present
// they are preferred over `changes` if the client can handle versioned document edits.
// 
// Since version 3.13.0 a workspace edit can contain resource operations as well. If resource
// operations are present clients need to execute the operations in the order in which they
// are provided. So a workspace edit for example can consist of the following two changes:
// (1) a create file a.txt and (2) a text document edit which insert text into file a.txt.
// 
// An invalid sequence (e.g. (1) delete file a.txt and (2) insert text into file a.txt) will
// cause failure of the operation. How the client recovers from the failure is described by
// the client capability: `workspace.workspaceEdit.failureHandling`
struct WorkspaceEdit
{
    // A map of change annotations that can be referenced in `AnnotatedTextEdit`s or create, rename and
    // delete file / folder operations.
    // 
    // Whether clients honor this property depends on the client capability `workspace.changeAnnotationSupport`.
    // 
    // @since 3.16.0
    std::optional<std::unordered_map<ChangeAnnotationIdentifier, ChangeAnnotation>> change_annotations;
    // Holds changes to existing resources.
    std::optional<std::unordered_map<std::string, std::vector<TextEdit>>> changes;
    // Depending on the client capability `workspace.workspaceEdit.resourceOperations` document changes
    // are either an array of `TextDocumentEdit`s to express changes to n different text documents
    // where each text document edit addresses a specific version of a text document. Or it can contain
    // above `TextDocumentEdit`s mixed with create, rename and delete file / folder operations.
    // 
    // Whether a client supports versioned document edits is expressed via
    // `workspace.workspaceEdit.documentChanges` client capability.
    // 
    // If a client neither supports `documentChanges` nor `workspace.workspaceEdit.resourceOperations` then
    // only plain `TextEdit`s using the `changes` property are supported.
    std::optional<std::vector<std::variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>>> document_changes;
};

template <>
struct glz::meta<WorkspaceEdit> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The options to register for file operations.
// 
// @since 3.16.0
struct FileOperationRegistrationOptions
{
    // The actual filters.
    std::vector<FileOperationFilter> filters;
};

template <>
struct glz::meta<FileOperationRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters sent in notifications/requests for user-initiated renames of
// files.
// 
// @since 3.16.0
struct RenameFilesParams
{
    // An array of all files/folders renamed in this operation. When a folder is renamed, only
    // the folder will be included, and not its children.
    std::vector<FileRename> files;
};

template <>
struct glz::meta<RenameFilesParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters sent in notifications/requests for user-initiated deletes of
// files.
// 
// @since 3.16.0
struct DeleteFilesParams
{
    // An array of all files/folders deleted in this operation.
    std::vector<FileDelete> files;
};

template <>
struct glz::meta<DeleteFilesParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct MonikerParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<MonikerParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Moniker definition to match LSIF 0.5 moniker definition.
// 
// @since 3.16.0
struct Moniker
{
    // The identifier of the moniker. The value is opaque in LSIF however
    // schema owners are allowed to define the structure if they want.
    std::string identifier;
    // The moniker kind if known.
    std::optional<MonikerKind> kind;
    // The scheme of the moniker. For example tsc or .Net
    std::string scheme;
    // The scope in which the moniker is unique
    UniquenessLevel unique;
};

template <>
struct glz::meta<Moniker> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct MonikerRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, MonikerRegistrationOptions> {
    template <auto Opts>
    static void op(const MonikerRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameter of a `textDocument/prepareTypeHierarchy` request.
// 
// @since 3.17.0
struct TypeHierarchyPrepareParams
{
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<TypeHierarchyPrepareParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.17.0
struct TypeHierarchyItem
{
    // A data entry field that is preserved between a type hierarchy prepare and
    // supertypes or subtypes requests. It could also be used to identify the
    // type hierarchy in the server, helping improve the performance on
    // resolving supertypes and subtypes.
    std::optional<LSPAny> data;
    // More detail for this item, e.g. the signature of a function.
    std::optional<std::string> detail;
    // The kind of this item.
    SymbolKind kind;
    // The name of this item.
    std::string name;
    // The range enclosing this symbol not including leading/trailing whitespace
    // but everything else, e.g. comments and code.
    Range range;
    // The range that should be selected and revealed when this symbol is being
    // picked, e.g. the name of a function. Must be contained by the
    // {@link TypeHierarchyItem.range `range`}.
    Range selection_range;
    // Tags for this item.
    std::optional<std::vector<SymbolTag>> tags;
    // The resource identifier of this item.
    std::string uri;
};

template <>
struct glz::meta<TypeHierarchyItem> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Type hierarchy options used during static or dynamic registration.
// 
// @since 3.17.0
struct TypeHierarchyRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, TypeHierarchyRegistrationOptions> {
    template <auto Opts>
    static void op(const TypeHierarchyRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameter of a `typeHierarchy/supertypes` request.
// 
// @since 3.17.0
struct TypeHierarchySupertypesParams
{
    TypeHierarchyItem item;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<TypeHierarchySupertypesParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameter of a `typeHierarchy/subtypes` request.
// 
// @since 3.17.0
struct TypeHierarchySubtypesParams
{
    TypeHierarchyItem item;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<TypeHierarchySubtypesParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A parameter literal used in inline value requests.
// 
// @since 3.17.0
struct InlineValueParams
{
    // Additional information about the context in which inline values were
    // requested.
    InlineValueContext context;
    // The document range for which inline values should be computed.
    Range range;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<InlineValueParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inline value options used during static or dynamic registration.
// 
// @since 3.17.0
struct InlineValueRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, InlineValueRegistrationOptions> {
    template <auto Opts>
    static void op(const InlineValueRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// A parameter literal used in inlay hint requests.
// 
// @since 3.17.0
struct InlayHintParams
{
    // The document range for which inlay hints should be computed.
    Range range;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<InlayHintParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inlay hint information.
// 
// @since 3.17.0
struct InlayHint
{
    // A data entry field that is preserved on an inlay hint between
    // a `textDocument/inlayHint` and a `inlayHint/resolve` request.
    std::optional<LSPAny> data;
    // The kind of this hint. Can be omitted in which case the client
    // should fall back to a reasonable default.
    std::optional<InlayHintKind> kind;
    // The label of this hint. A human readable string or an array of
    // InlayHintLabelPart label parts.
    // 
    // *Note* that neither the string nor the label part can be empty.
    std::variant<std::string, std::vector<InlayHintLabelPart>> label;
    // Render padding before the hint.
    // 
    // Note: Padding should use the editor's background color, not the
    // background color of the hint itself. That means padding can be used
    // to visually align/separate an inlay hint.
    std::optional<bool> padding_left;
    // Render padding after the hint.
    // 
    // Note: Padding should use the editor's background color, not the
    // background color of the hint itself. That means padding can be used
    // to visually align/separate an inlay hint.
    std::optional<bool> padding_right;
    // The position of this hint.
    // 
    // If multiple hints have the same position, they will be shown in the order
    // they appear in the response.
    Position position;
    // Optional text edits that are performed when accepting this inlay hint.
    // 
    // *Note* that edits are expected to change the document so that the inlay
    // hint (or its nearest variant) is now part of the document and the inlay
    // hint itself is now obsolete.
    std::optional<std::vector<TextEdit>> text_edits;
    // The tooltip text when you hover over this item.
    std::optional<std::variant<std::string, MarkupContent>> tooltip;
};

template <>
struct glz::meta<InlayHint> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inlay hint options used during static or dynamic registration.
// 
// @since 3.17.0
struct InlayHintRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    // The server provides support to resolve additional
    // information for an inlay hint item.
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, InlayHintRegistrationOptions> {
    template <auto Opts>
    static void op(const InlayHintRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "resolveProvider", v.resolve_provider,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters of the document diagnostic request.
// 
// @since 3.17.0
struct DocumentDiagnosticParams
{
    // The additional identifier  provided during registration.
    std::optional<std::string> identifier;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The result id of a previous response if provided.
    std::optional<std::string> previous_result_id;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentDiagnosticParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A partial result for a document diagnostic report.
// 
// @since 3.17.0
struct DocumentDiagnosticReportPartialResult
{
    std::unordered_map<std::string, std::variant<FullDocumentDiagnosticReport, UnchangedDocumentDiagnosticReport>> related_documents;
};

template <>
struct glz::meta<DocumentDiagnosticReportPartialResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Cancellation data returned from a diagnostic request.
// 
// @since 3.17.0
struct DiagnosticServerCancellationData
{
    bool retrigger_request;
};

template <>
struct glz::meta<DiagnosticServerCancellationData> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Diagnostic registration options.
// 
// @since 3.17.0
struct DiagnosticRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    // An optional identifier under which the diagnostics are
    // managed by the client.
    std::optional<std::string> identifier;
    // Whether the language has inter file dependencies meaning that
    // editing code in one file can result in a different diagnostic
    // set in another file. Inter file dependencies are common for
    // most programming languages and typically uncommon for linters.
    bool inter_file_dependencies;
    std::optional<bool> work_done_progress;
    // The server provides support for workspace diagnostics as well.
    bool workspace_diagnostics;
};

template <>
struct glz::to<glz::JSON, DiagnosticRegistrationOptions> {
    template <auto Opts>
    static void op(const DiagnosticRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "identifier", v.identifier,
            "interFileDependencies", v.inter_file_dependencies,
            "workDoneProgress", v.work_done_progress,
            "workspaceDiagnostics", v.workspace_diagnostics,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters of the workspace diagnostic request.
// 
// @since 3.17.0
struct WorkspaceDiagnosticParams
{
    // The additional identifier provided during registration.
    std::optional<std::string> identifier;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The currently known diagnostic reports with their
    // previous result ids.
    std::vector<PreviousResultId> previous_result_ids;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<WorkspaceDiagnosticParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A workspace diagnostic report.
// 
// @since 3.17.0
struct WorkspaceDiagnosticReport
{
    std::vector<WorkspaceDocumentDiagnosticReport> items;
};

template <>
struct glz::meta<WorkspaceDiagnosticReport> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A partial result for a workspace diagnostic report.
// 
// @since 3.17.0
struct WorkspaceDiagnosticReportPartialResult
{
    std::vector<WorkspaceDocumentDiagnosticReport> items;
};

template <>
struct glz::meta<WorkspaceDiagnosticReportPartialResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The params sent in an open notebook document notification.
// 
// @since 3.17.0
struct DidOpenNotebookDocumentParams
{
    // The text documents that represent the content
    // of a notebook cell.
    std::vector<TextDocumentItem> cell_text_documents;
    // The notebook document that got opened.
    NotebookDocument notebook_document;
};

template <>
struct glz::meta<DidOpenNotebookDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options specific to a notebook.
// 
// @since 3.17.0
struct NotebookDocumentSyncRegistrationOptions
{
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    // The notebooks to be synced
    std::vector<std::variant<NotebookDocumentFilterWithNotebook, NotebookDocumentFilterWithCells>> notebook_selector;
    // Whether save notification should be forwarded to
    // the server. Will only be honored if mode === `notebook`.
    std::optional<bool> save;
};

template <>
struct glz::meta<NotebookDocumentSyncRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The params sent in a change notebook document notification.
// 
// @since 3.17.0
struct DidChangeNotebookDocumentParams
{
    // The actual changes to the notebook document.
    // 
    // The changes describe single state changes to the notebook document.
    // So if there are two changes c1 (at array index 0) and c2 (at array
    // index 1) for a notebook in state S then c1 moves the notebook from
    // S to S' and c2 from S' to S''. So c1 is computed on the state S and
    // c2 is computed on the state S'.
    // 
    // To mirror the content of a notebook using change events use the following approach:
    // - start with the same initial content
    // - apply the 'notebookDocument/didChange' notifications in the order you receive them.
    // - apply the `NotebookChangeEvent`s in a single notification in the order
    // you receive them.
    NotebookDocumentChangeEvent change;
    // The notebook document that did change. The version number points
    // to the version after all provided changes have been applied. If
    // only the text document content of a cell changes the notebook version
    // doesn't necessarily have to change.
    VersionedNotebookDocumentIdentifier notebook_document;
};

template <>
struct glz::meta<DidChangeNotebookDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The params sent in a save notebook document notification.
// 
// @since 3.17.0
struct DidSaveNotebookDocumentParams
{
    // The notebook document that got saved.
    NotebookDocumentIdentifier notebook_document;
};

template <>
struct glz::meta<DidSaveNotebookDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The params sent in a close notebook document notification.
// 
// @since 3.17.0
struct DidCloseNotebookDocumentParams
{
    // The text documents that represent the content
    // of a notebook cell that got closed.
    std::vector<TextDocumentIdentifier> cell_text_documents;
    // The notebook document that got closed.
    NotebookDocumentIdentifier notebook_document;
};

template <>
struct glz::meta<DidCloseNotebookDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A parameter literal used in inline completion requests.
// 
// @since 3.18.0
// @proposed
struct InlineCompletionParams
{
    // Additional information about the context in which inline completions were
    // requested.
    InlineCompletionContext context;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<InlineCompletionParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a collection of {@link InlineCompletionItem inline completion items} to be presented in the editor.
// 
// @since 3.18.0
// @proposed
struct InlineCompletionList
{
    // The inline completion items
    std::vector<InlineCompletionItem> items;
};

template <>
struct glz::meta<InlineCompletionList> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// An inline completion item represents a text snippet that is proposed inline to complete text that is being typed.
// 
// @since 3.18.0
// @proposed
struct InlineCompletionItem
{
    // An optional {@link Command} that is executed *after* inserting this completion.
    std::optional<Command> command;
    // A text that is used to decide if this inline completion should be shown. When `falsy` the {@link InlineCompletionItem.insertText} is used.
    std::optional<std::string> filter_text;
    // The text to replace the range with. Must be set.
    std::variant<std::string, StringValue> insert_text;
    // The range to replace. Must begin and end on the same line.
    std::optional<Range> range;
};

template <>
struct glz::meta<InlineCompletionItem> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inline completion options used during static or dynamic registration.
// 
// @since 3.18.0
// @proposed
struct InlineCompletionRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, InlineCompletionRegistrationOptions> {
    template <auto Opts>
    static void op(const InlineCompletionRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "id", v.id,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for the `workspace/textDocumentContent` request.
// 
// @since 3.18.0
// @proposed
struct TextDocumentContentParams
{
    // The uri of the text document.
    std::string uri;
};

template <>
struct glz::meta<TextDocumentContentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Result of the `workspace/textDocumentContent` request.
// 
// @since 3.18.0
// @proposed
struct TextDocumentContentResult
{
    // The text content of the text document. Please note, that the content of
    // any subsequent open notifications for the text document might differ
    // from the returned content due to whitespace and line ending
    // normalizations done on the client
    std::string text;
};

template <>
struct glz::meta<TextDocumentContentResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Text document content provider registration options.
// 
// @since 3.18.0
// @proposed
struct TextDocumentContentRegistrationOptions
{
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
    // The schemes for which the server provides content.
    std::vector<std::string> schemes;
};

template <>
struct glz::meta<TextDocumentContentRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Parameters for the `workspace/textDocumentContent/refresh` request.
// 
// @since 3.18.0
// @proposed
struct TextDocumentContentRefreshParams
{
    // The uri of the text document to refresh.
    std::string uri;
};

template <>
struct glz::meta<TextDocumentContentRefreshParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct RegistrationParams
{
    std::vector<Registration> registrations;
};

template <>
struct glz::meta<RegistrationParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct UnregistrationParams
{
    std::vector<Unregistration> unregisterations;
};

template <>
struct glz::meta<UnregistrationParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct InitializeParams
{
    // The capabilities provided by the client (editor or tool)
    ClientCapabilities capabilities;
    // Information about the client
    // 
    // @since 3.15.0
    std::optional<ClientInfo> client_info;
    // User provided initialization options.
    std::optional<LSPAny> initialization_options;
    // The locale the client is currently showing the user interface
    // in. This must not necessarily be the locale of the operating
    // system.
    // 
    // Uses IETF language tags as the value's syntax
    // (See https://en.wikipedia.org/wiki/IETF_language_tag)
    // 
    // @since 3.16.0
    std::optional<std::string> locale;
    // The process Id of the parent process that started
    // the server.
    // 
    // Is `null` if the process has not been started by another process.
    // If the parent process is not alive then the server should exit.
    std::optional<int> process_id;
    // The rootPath of the workspace. Is null
    // if no folder is open.
    // 
    // @deprecated in favour of rootUri.
    std::optional<std::string> root_path;
    // The rootUri of the workspace. Is null if no
    // folder is open. If both `rootPath` and `rootUri` are set
    // `rootUri` wins.
    // 
    // @deprecated in favour of workspaceFolders.
    std::optional<std::string> root_uri;
    // The initial trace setting. If omitted trace is disabled ('off').
    std::optional<TraceValue> trace;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
    // The workspace folders configured in the client when the server starts.
    // 
    // This property is only available if the client supports workspace folders.
    // It can be `null` if the client supports workspace folders but none are
    // configured.
    // 
    // @since 3.6.0
    std::optional<std::vector<WorkspaceFolder>> workspace_folders;
};

template <>
struct glz::to<glz::JSON, InitializeParams> {
    template <auto Opts>
    static void op(const InitializeParams& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "capabilities", v.capabilities,
            "clientInfo", v.client_info,
            "initializationOptions", v.initialization_options,
            "locale", v.locale,
            "rootPath", v.root_path,
            "trace", v.trace,
            "workDoneToken", v.work_done_token,
            "workspaceFolders", v.workspace_folders,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.process_id.has_value()) {
            optional_fields.try_emplace("processId", *v.process_id);
        }
        if (v.root_uri.has_value()) {
            optional_fields.try_emplace("rootUri", *v.root_uri);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The result returned from an initialize request.
struct InitializeResult
{
    // The capabilities the language server provides.
    ServerCapabilities capabilities;
    // Information about the server.
    // 
    // @since 3.15.0
    std::optional<ServerInfo> server_info;
};

template <>
struct glz::meta<InitializeResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The data type of the ResponseError if the
// initialize request fails.
struct InitializeError
{
    // Indicates whether the client execute the following retry logic:
    // (1) show the message provided by the ResponseError to the user
    // (2) user selects retry or cancel
    // (3) if user selected retry the initialize method is sent again.
    bool retry;
};

template <>
struct glz::meta<InitializeError> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct InitializedParams
{
};

template <>
struct glz::meta<InitializedParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters of a change configuration notification.
struct DidChangeConfigurationParams
{
    // The actual changed settings
    LSPAny settings;
};

template <>
struct glz::meta<DidChangeConfigurationParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DidChangeConfigurationRegistrationOptions
{
    std::optional<std::variant<std::string, std::vector<std::string>>> section;
};

template <>
struct glz::meta<DidChangeConfigurationRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters of a notification message.
struct ShowMessageParams
{
    // The actual message.
    std::string message;
    // The message type. See {@link MessageType}
    MessageType type;
};

template <>
struct glz::meta<ShowMessageParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct ShowMessageRequestParams
{
    // The message action items to present.
    std::optional<std::vector<MessageActionItem>> actions;
    // The actual message.
    std::string message;
    // The message type. See {@link MessageType}
    MessageType type;
};

template <>
struct glz::meta<ShowMessageRequestParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct MessageActionItem
{
    // A short title like 'Retry', 'Open Log' etc.
    std::string title;
};

template <>
struct glz::meta<MessageActionItem> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The log message parameters.
struct LogMessageParams
{
    // The actual message.
    std::string message;
    // The message type. See {@link MessageType}
    MessageType type;
};

template <>
struct glz::meta<LogMessageParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters sent in an open text document notification
struct DidOpenTextDocumentParams
{
    // The document that was opened.
    TextDocumentItem text_document;
};

template <>
struct glz::meta<DidOpenTextDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The change text document notification's parameters.
struct DidChangeTextDocumentParams
{
    // The actual content changes. The content changes describe single state changes
    // to the document. So if there are two content changes c1 (at array index 0) and
    // c2 (at array index 1) for a document in state S then c1 moves the document from
    // S to S' and c2 from S' to S''. So c1 is computed on the state S and c2 is computed
    // on the state S'.
    // 
    // To mirror the content of a document using change events use the following approach:
    // - start with the same initial content
    // - apply the 'textDocument/didChange' notifications in the order you receive them.
    // - apply the `TextDocumentContentChangeEvent`s in a single notification in the order
    // you receive them.
    std::vector<TextDocumentContentChangeEvent> content_changes;
    // The document that did change. The version number points
    // to the version after all provided content changes have
    // been applied.
    VersionedTextDocumentIdentifier text_document;
};

template <>
struct glz::meta<DidChangeTextDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Describe options to be used when registered for text document change events.
struct TextDocumentChangeRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // How documents are synced to the server.
    TextDocumentSyncKind sync_kind;
};

template <>
struct glz::to<glz::JSON, TextDocumentChangeRegistrationOptions> {
    template <auto Opts>
    static void op(const TextDocumentChangeRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "syncKind", v.sync_kind,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters sent in a close text document notification
struct DidCloseTextDocumentParams
{
    // The document that was closed.
    TextDocumentIdentifier text_document;
};

template <>
struct glz::meta<DidCloseTextDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters sent in a save text document notification
struct DidSaveTextDocumentParams
{
    // Optional the content when saved. Depends on the includeText value
    // when the save notification was requested.
    std::optional<std::string> text;
    // The document that was saved.
    TextDocumentIdentifier text_document;
};

template <>
struct glz::meta<DidSaveTextDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Save registration options.
struct TextDocumentSaveRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The client is supposed to include the content on save.
    std::optional<bool> include_text;
};

template <>
struct glz::to<glz::JSON, TextDocumentSaveRegistrationOptions> {
    template <auto Opts>
    static void op(const TextDocumentSaveRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "includeText", v.include_text,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters sent in a will save text document notification.
struct WillSaveTextDocumentParams
{
    // The 'TextDocumentSaveReason'.
    TextDocumentSaveReason reason;
    // The document that will be saved.
    TextDocumentIdentifier text_document;
};

template <>
struct glz::meta<WillSaveTextDocumentParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A text edit applicable to a text document.
struct TextEdit
{
    // The string to be inserted. For delete operations use an
    // empty string.
    std::string new_text;
    // The range of the text document to be manipulated. To insert
    // text into a document create a range where start === end.
    Range range;
};

template <>
struct glz::meta<TextEdit> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The watched files change notification's parameters.
struct DidChangeWatchedFilesParams
{
    // The actual file events.
    std::vector<FileEvent> changes;
};

template <>
struct glz::meta<DidChangeWatchedFilesParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Describe options to be used when registered for text document change events.
struct DidChangeWatchedFilesRegistrationOptions
{
    // The watchers to register.
    std::vector<FileSystemWatcher> watchers;
};

template <>
struct glz::meta<DidChangeWatchedFilesRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The publish diagnostic notification's parameters.
struct PublishDiagnosticsParams
{
    // An array of diagnostic information items.
    std::vector<Diagnostic> diagnostics;
    // The URI for which diagnostic information is reported.
    std::string uri;
    // Optional the version number of the document the diagnostics are published for.
    // 
    // @since 3.15.0
    std::optional<int> version;
};

template <>
struct glz::meta<PublishDiagnosticsParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Completion parameters
struct CompletionParams
{
    // The completion context. This is only available it the client specifies
    // to send this using the client capability `textDocument.completion.contextSupport === true`
    std::optional<CompletionContext> context;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<CompletionParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A completion item represents a text snippet that is
// proposed to complete text that is being typed.
struct CompletionItem
{
    // An optional array of additional {@link TextEdit text edits} that are applied when
    // selecting this completion. Edits must not overlap (including the same insert position)
    // with the main {@link CompletionItem.textEdit edit} nor with themselves.
    // 
    // Additional text edits should be used to change text unrelated to the current cursor position
    // (for example adding an import statement at the top of the file if the completion item will
    // insert an unqualified type).
    std::optional<std::vector<TextEdit>> additional_text_edits;
    // An optional {@link Command command} that is executed *after* inserting this completion. *Note* that
    // additional modifications to the current document should be described with the
    // {@link CompletionItem.additionalTextEdits additionalTextEdits}-property.
    std::optional<Command> command;
    // An optional set of characters that when pressed while this completion is active will accept it first and
    // then type that character. *Note* that all commit characters should have `length=1` and that superfluous
    // characters will be ignored.
    std::optional<std::vector<std::string>> commit_characters;
    // A data entry field that is preserved on a completion item between a
    // {@link CompletionRequest} and a {@link CompletionResolveRequest}.
    std::optional<LSPAny> data;
    // Indicates if this item is deprecated.
    // @deprecated Use `tags` instead.
    std::optional<bool> deprecated;
    // A human-readable string with additional information
    // about this item, like type or symbol information.
    std::optional<std::string> detail;
    // A human-readable string that represents a doc-comment.
    std::optional<std::variant<std::string, MarkupContent>> documentation;
    // A string that should be used when filtering a set of
    // completion items. When `falsy` the {@link CompletionItem.label label}
    // is used.
    std::optional<std::string> filter_text;
    // A string that should be inserted into a document when selecting
    // this completion. When `falsy` the {@link CompletionItem.label label}
    // is used.
    // 
    // The `insertText` is subject to interpretation by the client side.
    // Some tools might not take the string literally. For example
    // VS Code when code complete is requested in this example
    // `con<cursor position>` and a completion item with an `insertText` of
    // `console` is provided it will only insert `sole`. Therefore it is
    // recommended to use `textEdit` instead since it avoids additional client
    // side interpretation.
    std::optional<std::string> insert_text;
    // The format of the insert text. The format applies to both the
    // `insertText` property and the `newText` property of a provided
    // `textEdit`. If omitted defaults to `InsertTextFormat.PlainText`.
    // 
    // Please note that the insertTextFormat doesn't apply to
    // `additionalTextEdits`.
    std::optional<InsertTextFormat> insert_text_format;
    // How whitespace and indentation is handled during completion
    // item insertion. If not provided the clients default value depends on
    // the `textDocument.completion.insertTextMode` client capability.
    // 
    // @since 3.16.0
    std::optional<InsertTextMode> insert_text_mode;
    // The kind of this completion item. Based of the kind
    // an icon is chosen by the editor.
    std::optional<CompletionItemKind> kind;
    // The label of this completion item.
    // 
    // The label property is also by default the text that
    // is inserted when selecting this completion.
    // 
    // If label details are provided the label itself should
    // be an unqualified name of the completion item.
    std::string label;
    // Additional details for the label
    // 
    // @since 3.17.0
    std::optional<CompletionItemLabelDetails> label_details;
    // Select this item when showing.
    // 
    // *Note* that only one completion item can be selected and that the
    // tool / client decides which item that is. The rule is that the *first*
    // item of those that match best is selected.
    std::optional<bool> preselect;
    // A string that should be used when comparing this item
    // with other items. When `falsy` the {@link CompletionItem.label label}
    // is used.
    std::optional<std::string> sort_text;
    // Tags for this completion item.
    // 
    // @since 3.15.0
    std::optional<std::vector<CompletionItemTag>> tags;
    // An {@link TextEdit edit} which is applied to a document when selecting
    // this completion. When an edit is provided the value of
    // {@link CompletionItem.insertText insertText} is ignored.
    // 
    // Most editors support two different operations when accepting a completion
    // item. One is to insert a completion text and the other is to replace an
    // existing text with a completion text. Since this can usually not be
    // predetermined by a server it can report both ranges. Clients need to
    // signal support for `InsertReplaceEdits` via the
    // `textDocument.completion.insertReplaceSupport` client capability
    // property.
    // 
    // *Note 1:* The text edit's range as well as both ranges from an insert
    // replace edit must be a [single line] and they must contain the position
    // at which completion has been requested.
    // *Note 2:* If an `InsertReplaceEdit` is returned the edit's insert range
    // must be a prefix of the edit's replace range, that means it must be
    // contained and starting at the same position.
    // 
    // @since 3.16.0 additional type `InsertReplaceEdit`
    std::optional<std::variant<TextEdit, InsertReplaceEdit>> text_edit;
    // The edit text used if the completion item is part of a CompletionList and
    // CompletionList defines an item default for the text edit range.
    // 
    // Clients will only honor this property if they opt into completion list
    // item defaults using the capability `completionList.itemDefaults`.
    // 
    // If not provided and a list's default range is provided the label
    // property is used as a text.
    // 
    // @since 3.17.0
    std::optional<std::string> text_edit_text;
};

template <>
struct glz::meta<CompletionItem> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a collection of {@link CompletionItem completion items} to be presented
// in the editor.
struct CompletionList
{
    // Specifies how fields from a completion item should be combined with those
    // from `completionList.itemDefaults`.
    // 
    // If unspecified, all fields will be treated as ApplyKind.Replace.
    // 
    // If a field's value is ApplyKind.Replace, the value from a completion item
    // (if provided and not `null`) will always be used instead of the value
    // from `completionItem.itemDefaults`.
    // 
    // If a field's value is ApplyKind.Merge, the values will be merged using
    // the rules defined against each field below.
    // 
    // Servers are only allowed to return `applyKind` if the client
    // signals support for this via the `completionList.applyKindSupport`
    // capability.
    // 
    // @since 3.18.0
    std::optional<CompletionItemApplyKinds> apply_kind;
    // This list it not complete. Further typing results in recomputing this list.
    // 
    // Recomputed lists have all their items replaced (not appended) in the
    // incomplete completion sessions.
    bool is_incomplete;
    // In many cases the items of an actual completion result share the same
    // value for properties like `commitCharacters` or the range of a text
    // edit. A completion list can therefore define item defaults which will
    // be used if a completion item itself doesn't specify the value.
    // 
    // If a completion list specifies a default value and a completion item
    // also specifies a corresponding value, the rules for combining these are
    // defined by `applyKinds` (if the client supports it), defaulting to
    // ApplyKind.Replace.
    // 
    // Servers are only allowed to return default values if the client
    // signals support for this via the `completionList.itemDefaults`
    // capability.
    // 
    // @since 3.17.0
    std::optional<CompletionItemDefaults> item_defaults;
    // The completion items.
    std::vector<CompletionItem> items;
};

template <>
struct glz::meta<CompletionList> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link CompletionRequest}.
struct CompletionRegistrationOptions
{
    // The list of all possible characters that commit a completion. This field can be used
    // if clients don't support individual commit characters per completion item. See
    // `ClientCapabilities.textDocument.completion.completionItem.commitCharactersSupport`
    // 
    // If a server provides both `allCommitCharacters` and commit characters on an individual
    // completion item the ones on the completion item win.
    // 
    // @since 3.2.0
    std::optional<std::vector<std::string>> all_commit_characters;
    // The server supports the following `CompletionItem` specific
    // capabilities.
    // 
    // @since 3.17.0
    std::optional<ServerCompletionItemOptions> completion_item;
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The server provides support to resolve additional
    // information for a completion item.
    std::optional<bool> resolve_provider;
    // Most tools trigger completion request automatically without explicitly requesting
    // it using a keyboard shortcut (e.g. Ctrl+Space). Typically they do so when the user
    // starts to type an identifier. For example if the user types `c` in a JavaScript file
    // code complete will automatically pop up present `console` besides others as a
    // completion item. Characters that make up identifiers don't need to be listed here.
    // 
    // If code complete should automatically be trigger on characters not being valid inside
    // an identifier (for example `.` in JavaScript) list them in `triggerCharacters`.
    std::optional<std::vector<std::string>> trigger_characters;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, CompletionRegistrationOptions> {
    template <auto Opts>
    static void op(const CompletionRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "allCommitCharacters", v.all_commit_characters,
            "completionItem", v.completion_item,
            "resolveProvider", v.resolve_provider,
            "triggerCharacters", v.trigger_characters,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link HoverRequest}.
struct HoverParams
{
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<HoverParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The result of a hover request.
struct Hover
{
    // The hover's content
    std::variant<MarkupContent, MarkedString, std::vector<MarkedString>> contents;
    // An optional range inside the text document that is used to
    // visualize the hover, e.g. by changing the background color.
    std::optional<Range> range;
};

template <>
struct glz::meta<Hover> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link HoverRequest}.
struct HoverRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, HoverRegistrationOptions> {
    template <auto Opts>
    static void op(const HoverRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link SignatureHelpRequest}.
struct SignatureHelpParams
{
    // The signature help context. This is only available if the client specifies
    // to send this using the client capability `textDocument.signatureHelp.contextSupport === true`
    // 
    // @since 3.15.0
    std::optional<SignatureHelpContext> context;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<SignatureHelpParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Signature help represents the signature of something
// callable. There can be multiple signature but only one
// active and only one active parameter.
struct SignatureHelp
{
    // The active parameter of the active signature.
    // 
    // If `null`, no parameter of the signature is active (for example a named
    // argument that does not match any declared parameters). This is only valid
    // if the client specifies the client capability
    // `textDocument.signatureHelp.noActiveParameterSupport === true`
    // 
    // If omitted or the value lies outside the range of
    // `signatures[activeSignature].parameters` defaults to 0 if the active
    // signature has parameters.
    // 
    // If the active signature has no parameters it is ignored.
    // 
    // In future version of the protocol this property might become
    // mandatory (but still nullable) to better express the active parameter if
    // the active signature does have any.
    std::optional<unsigned int> active_parameter;
    // The active signature. If omitted or the value lies outside the
    // range of `signatures` the value defaults to zero or is ignored if
    // the `SignatureHelp` has no signatures.
    // 
    // Whenever possible implementors should make an active decision about
    // the active signature and shouldn't rely on a default value.
    // 
    // In future version of the protocol this property might become
    // mandatory to better express this.
    std::optional<unsigned int> active_signature;
    // One or more signatures.
    std::vector<SignatureInformation> signatures;
};

template <>
struct glz::meta<SignatureHelp> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link SignatureHelpRequest}.
struct SignatureHelpRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // List of characters that re-trigger signature help.
    // 
    // These trigger characters are only active when signature help is already showing. All trigger characters
    // are also counted as re-trigger characters.
    // 
    // @since 3.15.0
    std::optional<std::vector<std::string>> retrigger_characters;
    // List of characters that trigger signature help automatically.
    std::optional<std::vector<std::string>> trigger_characters;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, SignatureHelpRegistrationOptions> {
    template <auto Opts>
    static void op(const SignatureHelpRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "retriggerCharacters", v.retrigger_characters,
            "triggerCharacters", v.trigger_characters,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link DefinitionRequest}.
struct DefinitionParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DefinitionParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link DefinitionRequest}.
struct DefinitionRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DefinitionRegistrationOptions> {
    template <auto Opts>
    static void op(const DefinitionRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link ReferencesRequest}.
struct ReferenceParams
{
    ReferenceContext context;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<ReferenceParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link ReferencesRequest}.
struct ReferenceRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, ReferenceRegistrationOptions> {
    template <auto Opts>
    static void op(const ReferenceRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link DocumentHighlightRequest}.
struct DocumentHighlightParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentHighlightParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A document highlight is a range inside a text document which deserves
// special attention. Usually a document highlight is visualized by changing
// the background color of its range.
struct DocumentHighlight
{
    // The highlight kind, default is {@link DocumentHighlightKind.Text text}.
    std::optional<DocumentHighlightKind> kind;
    // The range this highlight applies to.
    Range range;
};

template <>
struct glz::meta<DocumentHighlight> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link DocumentHighlightRequest}.
struct DocumentHighlightRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DocumentHighlightRegistrationOptions> {
    template <auto Opts>
    static void op(const DocumentHighlightRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// Parameters for a {@link DocumentSymbolRequest}.
struct DocumentSymbolParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentSymbolParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents information about programming constructs like variables, classes,
// interfaces etc.
struct SymbolInformation
{
    // The name of the symbol containing this symbol. This information is for
    // user interface purposes (e.g. to render a qualifier in the user interface
    // if necessary). It can't be used to re-infer a hierarchy for the document
    // symbols.
    std::optional<std::string> container_name;
    // Indicates if this symbol is deprecated.
    // 
    // @deprecated Use tags instead
    std::optional<bool> deprecated;
    // The kind of this symbol.
    SymbolKind kind;
    // The location of this symbol. The location's range is used by a tool
    // to reveal the location in the editor. If the symbol is selected in the
    // tool the range's start information is used to position the cursor. So
    // the range usually spans more than the actual symbol's name and does
    // normally include things like visibility modifiers.
    // 
    // The range doesn't have to denote a node range in the sense of an abstract
    // syntax tree. It can therefore not be used to re-construct a hierarchy of
    // the symbols.
    Location location;
    // The name of this symbol.
    std::string name;
    // Tags for this symbol.
    // 
    // @since 3.16.0
    std::optional<std::vector<SymbolTag>> tags;
};

template <>
struct glz::meta<SymbolInformation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents programming constructs like variables, classes, interfaces etc.
// that appear in a document. Document symbols can be hierarchical and they
// have two ranges: one that encloses its definition and one that points to
// its most interesting range, e.g. the range of an identifier.
struct DocumentSymbol
{
    // Children of this symbol, e.g. properties of a class.
    std::optional<std::vector<DocumentSymbol>> children;
    // Indicates if this symbol is deprecated.
    // 
    // @deprecated Use tags instead
    std::optional<bool> deprecated;
    // More detail for this symbol, e.g the signature of a function.
    std::optional<std::string> detail;
    // The kind of this symbol.
    SymbolKind kind;
    // The name of this symbol. Will be displayed in the user interface and therefore must not be
    // an empty string or a string only consisting of white spaces.
    std::string name;
    // The range enclosing this symbol not including leading/trailing whitespace but everything else
    // like comments. This information is typically used to determine if the clients cursor is
    // inside the symbol to reveal in the symbol in the UI.
    Range range;
    // The range that should be selected and revealed when this symbol is being picked, e.g the name of a function.
    // Must be contained by the `range`.
    Range selection_range;
    // Tags for this document symbol.
    // 
    // @since 3.16.0
    std::optional<std::vector<SymbolTag>> tags;
};

template <>
struct glz::meta<DocumentSymbol> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link DocumentSymbolRequest}.
struct DocumentSymbolRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // A human-readable string that is shown when multiple outlines trees
    // are shown for the same document.
    // 
    // @since 3.16.0
    std::optional<std::string> label;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DocumentSymbolRegistrationOptions> {
    template <auto Opts>
    static void op(const DocumentSymbolRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "label", v.label,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters of a {@link CodeActionRequest}.
struct CodeActionParams
{
    // Context carrying additional information.
    CodeActionContext context;
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The range for which the command was invoked.
    Range range;
    // The document in which the command was invoked.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<CodeActionParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a reference to a command. Provides a title which
// will be used to represent a command in the UI and, optionally,
// an array of arguments which will be passed to the command handler
// function when invoked.
struct Command
{
    // Arguments that the command handler should be
    // invoked with.
    std::optional<std::vector<LSPAny>> arguments;
    // The identifier of the actual command handler.
    std::string command;
    // Title of the command, like `save`.
    std::string title;
    // An optional tooltip.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<std::string> tooltip;
};

template <>
struct glz::meta<Command> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A code action represents a change that can be performed in code, e.g. to fix a problem or
// to refactor code.
// 
// A CodeAction must set either `edit` and/or a `command`. If both are supplied, the `edit` is applied first, then the `command` is executed.
struct CodeAction
{
    // A command this code action executes. If a code action
    // provides an edit and a command, first the edit is
    // executed and then the command.
    std::optional<Command> command;
    // A data entry field that is preserved on a code action between
    // a `textDocument/codeAction` and a `codeAction/resolve` request.
    // 
    // @since 3.16.0
    std::optional<LSPAny> data;
    // The diagnostics that this code action resolves.
    std::optional<std::vector<Diagnostic>> diagnostics;
    // Marks that the code action cannot currently be applied.
    // 
    // Clients should follow the following guidelines regarding disabled code actions:
    // 
    // - Disabled code actions are not shown in automatic [lightbulbs](https://code.visualstudio.com/docs/editor/editingevolved#_code-action)
    // code action menus.
    // 
    // - Disabled actions are shown as faded out in the code action menu when the user requests a more specific type
    // of code action, such as refactorings.
    // 
    // - If the user has a [keybinding](https://code.visualstudio.com/docs/editor/refactoring#_keybindings-for-code-actions)
    // that auto applies a code action and only disabled code actions are returned, the client should show the user an
    // error message with `reason` in the editor.
    // 
    // @since 3.16.0
    std::optional<CodeActionDisabled> disabled;
    // The workspace edit this code action performs.
    std::optional<WorkspaceEdit> edit;
    // Marks this as a preferred action. Preferred actions are used by the `auto fix` command and can be targeted
    // by keybindings.
    // 
    // A quick fix should be marked preferred if it properly addresses the underlying error.
    // A refactoring should be marked preferred if it is the most reasonable choice of actions to take.
    // 
    // @since 3.15.0
    std::optional<bool> is_preferred;
    // The kind of the code action.
    // 
    // Used to filter code actions.
    std::optional<CodeActionKind> kind;
    // Tags for this code action.
    // 
    // @since 3.18.0 - proposed
    std::optional<std::vector<CodeActionTag>> tags;
    // A short, human-readable, title for this code action.
    std::string title;
};

template <>
struct glz::meta<CodeAction> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link CodeActionRequest}.
struct CodeActionRegistrationOptions
{
    // CodeActionKinds that this server may return.
    // 
    // The list of kinds may be generic, such as `CodeActionKind.Refactor`, or the server
    // may list out every specific kind they provide.
    std::optional<std::vector<CodeActionKind>> code_action_kinds;
    // Static documentation for a class of code actions.
    // 
    // Documentation from the provider should be shown in the code actions menu if either:
    // 
    // - Code actions of `kind` are requested by the editor. In this case, the editor will show the documentation that
    // most closely matches the requested code action kind. For example, if a provider has documentation for
    // both `Refactor` and `RefactorExtract`, when the user requests code actions for `RefactorExtract`,
    // the editor will use the documentation for `RefactorExtract` instead of the documentation for `Refactor`.
    // 
    // - Any code actions of `kind` are returned by the provider.
    // 
    // At most one documentation entry should be shown per provider.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<std::vector<CodeActionKindDocumentation>> documentation;
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // The server provides support to resolve additional
    // information for a code action.
    // 
    // @since 3.16.0
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, CodeActionRegistrationOptions> {
    template <auto Opts>
    static void op(const CodeActionRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "codeActionKinds", v.code_action_kinds,
            "documentation", v.documentation,
            "resolveProvider", v.resolve_provider,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters of a {@link WorkspaceSymbolRequest}.
struct WorkspaceSymbolParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // A query string to filter symbols by. Clients may send an empty
    // string here to request all symbols.
    // 
    // The `query`-parameter should be interpreted in a *relaxed way* as editors
    // will apply their own highlighting and scoring on the results. A good rule
    // of thumb is to match case-insensitive and to simply check that the
    // characters of *query* appear in their order in a candidate symbol.
    // Servers shouldn't use prefix, substring, or similar strict matching.
    std::string query;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<WorkspaceSymbolParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A special workspace symbol that supports locations without a range.
// 
// See also SymbolInformation.
// 
// @since 3.17.0
struct WorkspaceSymbol
{
    // The name of the symbol containing this symbol. This information is for
    // user interface purposes (e.g. to render a qualifier in the user interface
    // if necessary). It can't be used to re-infer a hierarchy for the document
    // symbols.
    std::optional<std::string> container_name;
    // A data entry field that is preserved on a workspace symbol between a
    // workspace symbol request and a workspace symbol resolve request.
    std::optional<LSPAny> data;
    // The kind of this symbol.
    SymbolKind kind;
    // The location of the symbol. Whether a server is allowed to
    // return a location without a range depends on the client
    // capability `workspace.symbol.resolveSupport`.
    // 
    // See SymbolInformation#location for more details.
    std::variant<Location, LocationUriOnly> location;
    // The name of this symbol.
    std::string name;
    // Tags for this symbol.
    // 
    // @since 3.16.0
    std::optional<std::vector<SymbolTag>> tags;
};

template <>
struct glz::meta<WorkspaceSymbol> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link WorkspaceSymbolRequest}.
struct WorkspaceSymbolRegistrationOptions
{
    // The server provides support to resolve additional
    // information for a workspace symbol.
    // 
    // @since 3.17.0
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<WorkspaceSymbolRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters of a {@link CodeLensRequest}.
struct CodeLensParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The document to request code lens for.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<CodeLensParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A code lens represents a {@link Command command} that should be shown along with
// source text, like the number of references, a way to run tests, etc.
// 
// A code lens is _unresolved_ when no command is associated to it. For performance
// reasons the creation of a code lens and resolving should be done in two stages.
struct CodeLens
{
    // The command this code lens represents.
    std::optional<Command> command;
    // A data entry field that is preserved on a code lens item between
    // a {@link CodeLensRequest} and a {@link CodeLensResolveRequest}
    std::optional<LSPAny> data;
    // The range in which this code lens is valid. Should only span a single line.
    Range range;
};

template <>
struct glz::meta<CodeLens> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link CodeLensRequest}.
struct CodeLensRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // Code lens has a resolve provider as well.
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, CodeLensRegistrationOptions> {
    template <auto Opts>
    static void op(const CodeLensRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "resolveProvider", v.resolve_provider,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters of a {@link DocumentLinkRequest}.
struct DocumentLinkParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
    // The document to provide document links for.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentLinkParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A document link is a range in a text document that links to an internal or external resource, like another
// text document or a web site.
struct DocumentLink
{
    // A data entry field that is preserved on a document link between a
    // DocumentLinkRequest and a DocumentLinkResolveRequest.
    std::optional<LSPAny> data;
    // The range this link applies to.
    Range range;
    // The uri this link points to. If missing a resolve request is sent later.
    std::optional<std::string> target;
    // The tooltip text when you hover over this link.
    // 
    // If a tooltip is provided, is will be displayed in a string that includes instructions on how to
    // trigger the link, such as `{0} (ctrl + click)`. The specific instructions vary depending on OS,
    // user settings, and localization.
    // 
    // @since 3.15.0
    std::optional<std::string> tooltip;
};

template <>
struct glz::meta<DocumentLink> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link DocumentLinkRequest}.
struct DocumentLinkRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // Document links have a resolve provider as well.
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DocumentLinkRegistrationOptions> {
    template <auto Opts>
    static void op(const DocumentLinkRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "resolveProvider", v.resolve_provider,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters of a {@link DocumentFormattingRequest}.
struct DocumentFormattingParams
{
    // The format options.
    FormattingOptions options;
    // The document to format.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentFormattingParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link DocumentFormattingRequest}.
struct DocumentFormattingRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DocumentFormattingRegistrationOptions> {
    template <auto Opts>
    static void op(const DocumentFormattingRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters of a {@link DocumentRangeFormattingRequest}.
struct DocumentRangeFormattingParams
{
    // The format options
    FormattingOptions options;
    // The range to format
    Range range;
    // The document to format.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentRangeFormattingParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link DocumentRangeFormattingRequest}.
struct DocumentRangeFormattingRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // Whether the server supports formatting multiple ranges at once.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> ranges_support;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, DocumentRangeFormattingRegistrationOptions> {
    template <auto Opts>
    static void op(const DocumentRangeFormattingRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "rangesSupport", v.ranges_support,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters of a {@link DocumentRangesFormattingRequest}.
// 
// @since 3.18.0
// @proposed
struct DocumentRangesFormattingParams
{
    // The format options
    FormattingOptions options;
    // The ranges to format
    std::vector<Range> ranges;
    // The document to format.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<DocumentRangesFormattingParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters of a {@link DocumentOnTypeFormattingRequest}.
struct DocumentOnTypeFormattingParams
{
    // The character that has been typed that triggered the formatting
    // on type request. That is not necessarily the last character that
    // got inserted into the document since the client could auto insert
    // characters as well (e.g. like automatic brace completion).
    std::string ch;
    // The formatting options.
    FormattingOptions options;
    // The position around which the on type formatting should happen.
    // This is not necessarily the exact position where the character denoted
    // by the property `ch` got typed.
    Position position;
    // The document to format.
    TextDocumentIdentifier text_document;
};

template <>
struct glz::meta<DocumentOnTypeFormattingParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link DocumentOnTypeFormattingRequest}.
struct DocumentOnTypeFormattingRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // A character on which formatting should be triggered, like `{`.
    std::string first_trigger_character;
    // More trigger characters.
    std::optional<std::vector<std::string>> more_trigger_character;
};

template <>
struct glz::to<glz::JSON, DocumentOnTypeFormattingRegistrationOptions> {
    template <auto Opts>
    static void op(const DocumentOnTypeFormattingRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "firstTriggerCharacter", v.first_trigger_character,
            "moreTriggerCharacter", v.more_trigger_character,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// The parameters of a {@link RenameRequest}.
struct RenameParams
{
    // The new name of the symbol. If the given name is not valid the
    // request must return a {@link ResponseError} with an
    // appropriate message set.
    std::string new_name;
    // The position at which this request was sent.
    Position position;
    // The document to rename.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<RenameParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link RenameRequest}.
struct RenameRegistrationOptions
{
    // A document selector to identify the scope of the registration. If set to null
    // the document selector provided on the client side will be used.
    std::optional<DocumentSelector> document_selector;
    // Renames should be checked and tested before being executed.
    // 
    // @since version 3.12.0
    std::optional<bool> prepare_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::to<glz::JSON, RenameRegistrationOptions> {
    template <auto Opts>
    static void op(const RenameRegistrationOptions& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "prepareProvider", v.prepare_provider,
            "workDoneProgress", v.work_done_progress,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.document_selector.has_value()) {
            optional_fields.try_emplace("documentSelector", *v.document_selector);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

struct PrepareRenameParams
{
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<PrepareRenameParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters of a {@link ExecuteCommandRequest}.
struct ExecuteCommandParams
{
    // Arguments that the command should be invoked with.
    std::optional<std::vector<LSPAny>> arguments;
    // The identifier of the actual command handler.
    std::string command;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<ExecuteCommandParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Registration options for a {@link ExecuteCommandRequest}.
struct ExecuteCommandRegistrationOptions
{
    // The commands to be executed on the server
    std::vector<std::string> commands;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<ExecuteCommandRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The parameters passed via an apply workspace edit request.
struct ApplyWorkspaceEditParams
{
    // The edits to apply.
    WorkspaceEdit edit;
    // An optional label of the workspace edit. This label is
    // presented in the user interface for example on an undo
    // stack to undo the workspace edit.
    std::optional<std::string> label;
    // Additional data about the edit.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<WorkspaceEditMetadata> metadata;
};

template <>
struct glz::meta<ApplyWorkspaceEditParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The result returned from the apply workspace edit request.
// 
// @since 3.17 renamed from ApplyWorkspaceEditResponse
struct ApplyWorkspaceEditResult
{
    // Indicates whether the edit was applied or not.
    bool applied;
    // Depending on the client's failure handling strategy `failedChange` might
    // contain the index of the change that failed. This property is only available
    // if the client signals a `failureHandlingStrategy` in its client capabilities.
    std::optional<unsigned int> failed_change;
    // An optional textual description for why the edit was not applied.
    // This may be used by the server for diagnostic logging or to provide
    // a suitable error for a request that triggered the edit.
    std::optional<std::string> failure_reason;
};

template <>
struct glz::meta<ApplyWorkspaceEditResult> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkDoneProgressBegin
{
    // Controls if a cancel button should show to allow the user to cancel the
    // long running operation. Clients that don't support cancellation are allowed
    // to ignore the setting.
    std::optional<bool> cancellable;
    std::string kind;
    // Optional, more detailed associated progress message. Contains
    // complementary information to the `title`.
    // 
    // Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
    // If unset, the previous progress message (if any) is still valid.
    std::optional<std::string> message;
    // Optional progress percentage to display (value 100 is considered 100%).
    // If not provided infinite progress is assumed and clients are allowed
    // to ignore the `percentage` value in subsequent in report notifications.
    // 
    // The value should be steadily rising. Clients are free to ignore values
    // that are not following this rule. The value range is [0, 100].
    std::optional<unsigned int> percentage;
    // Mandatory title of the progress operation. Used to briefly inform about
    // the kind of operation being performed.
    // 
    // Examples: "Indexing" or "Linking dependencies".
    std::string title;
};

template <>
struct glz::meta<WorkDoneProgressBegin> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkDoneProgressReport
{
    // Controls enablement state of a cancel button.
    // 
    // Clients that don't support cancellation or don't support controlling the button's
    // enablement state are allowed to ignore the property.
    std::optional<bool> cancellable;
    std::string kind;
    // Optional, more detailed associated progress message. Contains
    // complementary information to the `title`.
    // 
    // Examples: "3/25 files", "project/src/module2", "node_modules/some_dep".
    // If unset, the previous progress message (if any) is still valid.
    std::optional<std::string> message;
    // Optional progress percentage to display (value 100 is considered 100%).
    // If not provided infinite progress is assumed and clients are allowed
    // to ignore the `percentage` value in subsequent in report notifications.
    // 
    // The value should be steadily rising. Clients are free to ignore values
    // that are not following this rule. The value range is [0, 100]
    std::optional<unsigned int> percentage;
};

template <>
struct glz::meta<WorkDoneProgressReport> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkDoneProgressEnd
{
    std::string kind;
    // Optional, a final message indicating to for example indicate the outcome
    // of the operation.
    std::optional<std::string> message;
};

template <>
struct glz::meta<WorkDoneProgressEnd> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct SetTraceParams
{
    TraceValue value;
};

template <>
struct glz::meta<SetTraceParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct LogTraceParams
{
    std::string message;
    std::optional<std::string> verbose;
};

template <>
struct glz::meta<LogTraceParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct CancelParams
{
    // The request id to cancel.
    std::variant<int, std::string> id;
};

template <>
struct glz::meta<CancelParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct ProgressParams
{
    // The progress token provided by the client or server.
    ProgressToken token;
    // The progress data.
    LSPAny value;
};

template <>
struct glz::meta<ProgressParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A parameter literal used in requests to pass a text document and a position inside that
// document.
struct TextDocumentPositionParams
{
    // The position inside the text document.
    Position position;
    // The text document.
    TextDocumentIdentifier text_document;
};

template <>
struct glz::meta<TextDocumentPositionParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkDoneProgressParams
{
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::meta<WorkDoneProgressParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct PartialResultParams
{
    // An optional token that a server can use to report partial results (e.g. streaming) to
    // the client.
    std::optional<ProgressToken> partial_result_token;
};

template <>
struct glz::meta<PartialResultParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents the connection of two locations. Provides additional metadata over normal {@link Location locations},
// including an origin range.
struct LocationLink
{
    // Span of the origin of this link.
    // 
    // Used as the underlined span for mouse interaction. Defaults to the word range at
    // the definition position.
    std::optional<Range> origin_selection_range;
    // The full target range of this link. If the target for example is a symbol then target range is the
    // range enclosing this symbol not including leading/trailing whitespace but everything else
    // like comments. This information is typically used to highlight the range in the editor.
    Range target_range;
    // The range that should be selected and revealed when this link is being followed, e.g the name of a function.
    // Must be contained by the `targetRange`. See also `DocumentSymbol#range`
    Range target_selection_range;
    // The target resource identifier of this link.
    std::string target_uri;
};

template <>
struct glz::meta<LocationLink> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A range in a text document expressed as (zero-based) start and end positions.
// 
// If you want to specify a range that contains a line including the line ending
// character(s) then use an end position denoting the start of the next line.
// For example:
// ```ts
// {
// start: { line: 5, character: 23 }
// end : { line 6, character : 0 }
// }
// ```
struct Range
{
    // The range's end position.
    Position end;
    // The range's start position.
    Position start;
};

template <>
struct glz::meta<Range> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct ImplementationOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<ImplementationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Static registration options to be returned in the initialize
// request.
struct StaticRegistrationOptions
{
    // The id used to register the request. The id can be used to deregister
    // the request again. See also Registration#id.
    std::optional<std::string> id;
};

template <>
struct glz::meta<StaticRegistrationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct TypeDefinitionOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<TypeDefinitionOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The workspace folder change event.
struct WorkspaceFoldersChangeEvent
{
    // The array of added workspace folders
    std::vector<WorkspaceFolder> added;
    // The array of the removed workspace folders
    std::vector<WorkspaceFolder> removed;
};

template <>
struct glz::meta<WorkspaceFoldersChangeEvent> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct ConfigurationItem
{
    // The scope to get the configuration section for.
    std::optional<std::string> scope_uri;
    // The configuration section asked for.
    std::optional<std::string> section;
};

template <>
struct glz::meta<ConfigurationItem> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A literal to identify a text document in the client.
struct TextDocumentIdentifier
{
    // The text document's uri.
    std::string uri;
};

template <>
struct glz::meta<TextDocumentIdentifier> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a color in RGBA space.
struct Color
{
    // The alpha component of this color in the range [0-1].
    double alpha;
    // The blue component of this color in the range [0-1].
    double blue;
    // The green component of this color in the range [0-1].
    double green;
    // The red component of this color in the range [0-1].
    double red;
};

template <>
struct glz::meta<Color> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DocumentColorOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DocumentColorOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct FoldingRangeOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<FoldingRangeOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DeclarationOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DeclarationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Position in a text document expressed as zero-based line and character
// offset. Prior to 3.17 the offsets were always based on a UTF-16 string
// representation. So a string of the form `a𐐀b` the character offset of the
// character `a` is 0, the character offset of `𐐀` is 1 and the character
// offset of b is 3 since `𐐀` is represented using two code units in UTF-16.
// Since 3.17 clients and servers can agree on a different string encoding
// representation (e.g. UTF-8). The client announces it's supported encoding
// via the client capability [`general.positionEncodings`](https://microsoft.github.io/language-server-protocol/specifications/specification-current/#clientCapabilities).
// The value is an array of position encodings the client supports, with
// decreasing preference (e.g. the encoding at index `0` is the most preferred
// one). To stay backwards compatible the only mandatory encoding is UTF-16
// represented via the string `utf-16`. The server can pick one of the
// encodings offered by the client and signals that encoding back to the
// client via the initialize result's property
// [`capabilities.positionEncoding`](https://microsoft.github.io/language-server-protocol/specifications/specification-current/#serverCapabilities). If the string value
// `utf-16` is missing from the client's capability `general.positionEncodings`
// servers can safely assume that the client supports UTF-16. If the server
// omits the position encoding in its initialize result the encoding defaults
// to the string value `utf-16`. Implementation considerations: since the
// conversion from one encoding into another requires the content of the
// file / line the conversion is best done where the file is read which is
// usually on the server side.
// 
// Positions are line end character agnostic. So you can not specify a position
// that denotes `\r|\n` or `\n|` where `|` represents the character offset.
// 
// @since 3.17.0 - support for negotiated position encoding.
struct Position
{
    // Character offset on a line in a document (zero-based).
    // 
    // The meaning of this offset is determined by the negotiated
    // `PositionEncodingKind`.
    unsigned int character;
    // Line position in a document (zero-based).
    unsigned int line;
};

template <>
struct glz::meta<Position> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct SelectionRangeOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<SelectionRangeOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Call hierarchy options used during static registration.
// 
// @since 3.16.0
struct CallHierarchyOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<CallHierarchyOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensOptions
{
    // Server supports providing semantic tokens for a full document.
    std::optional<std::variant<bool, SemanticTokensFullDelta>> full;
    // The legend used by the server
    SemanticTokensLegend legend;
    // Server supports providing semantic tokens for a specific range
    // of a document.
    std::optional<std::variant<bool, LSPObject>> range;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<SemanticTokensOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensEdit
{
    // The elements to insert.
    std::optional<std::vector<unsigned int>> data;
    // The count of elements to remove.
    unsigned int delete_count;
    // The start offset of the edit.
    unsigned int start;
};

template <>
struct glz::meta<SemanticTokensEdit> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct LinkedEditingRangeOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<LinkedEditingRangeOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents information on a file/folder create.
// 
// @since 3.16.0
struct FileCreate
{
    // A file:// URI for the location of the file/folder being created.
    std::string uri;
};

template <>
struct glz::meta<FileCreate> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Describes textual changes on a text document. A TextDocumentEdit describes all changes
// on a document version Si and after they are applied move the document to version Si+1.
// So the creator of a TextDocumentEdit doesn't need to sort the array of edits or do any
// kind of ordering. However the edits must be non overlapping.
struct TextDocumentEdit
{
    // The edits to be applied.
    // 
    // @since 3.16.0 - support for AnnotatedTextEdit. This is guarded using a
    // client capability.
    // 
    // @since 3.18.0 - support for SnippetTextEdit. This is guarded using a
    // client capability.
    std::vector<std::variant<TextEdit, AnnotatedTextEdit, SnippetTextEdit>> edits;
    // The text document to change.
    OptionalVersionedTextDocumentIdentifier text_document;
};

template <>
struct glz::meta<TextDocumentEdit> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Create file operation.
struct CreateFile
{
    // An optional annotation identifier describing the operation.
    // 
    // @since 3.16.0
    std::optional<ChangeAnnotationIdentifier> annotation_id;
    // The resource operation kind.
    std::string kind;
    // A create
    std::string kind;
    // Additional options
    std::optional<CreateFileOptions> options;
    // The resource to create.
    std::string uri;
};

template <>
struct glz::meta<CreateFile> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Rename file operation
struct RenameFile
{
    // An optional annotation identifier describing the operation.
    // 
    // @since 3.16.0
    std::optional<ChangeAnnotationIdentifier> annotation_id;
    // The resource operation kind.
    std::string kind;
    // A rename
    std::string kind;
    // The new location.
    std::string new_uri;
    // The old (existing) location.
    std::string old_uri;
    // Rename options.
    std::optional<RenameFileOptions> options;
};

template <>
struct glz::meta<RenameFile> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Delete file operation
struct DeleteFile
{
    // An optional annotation identifier describing the operation.
    // 
    // @since 3.16.0
    std::optional<ChangeAnnotationIdentifier> annotation_id;
    // The resource operation kind.
    std::string kind;
    // A delete
    std::string kind;
    // Delete options.
    std::optional<DeleteFileOptions> options;
    // The file to delete.
    std::string uri;
};

template <>
struct glz::meta<DeleteFile> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Additional information that describes document changes.
// 
// @since 3.16.0
struct ChangeAnnotation
{
    // A human-readable string which is rendered less prominent in
    // the user interface.
    std::optional<std::string> description;
    // A human-readable string describing the actual change. The string
    // is rendered prominent in the user interface.
    std::string label;
    // A flag which indicates that user confirmation is needed
    // before applying the change.
    std::optional<bool> needs_confirmation;
};

template <>
struct glz::meta<ChangeAnnotation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A filter to describe in which file operation requests or notifications
// the server is interested in receiving.
// 
// @since 3.16.0
struct FileOperationFilter
{
    // The actual file operation pattern.
    FileOperationPattern pattern;
    // A Uri scheme like `file` or `untitled`.
    std::optional<std::string> scheme;
};

template <>
struct glz::meta<FileOperationFilter> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents information on a file/folder rename.
// 
// @since 3.16.0
struct FileRename
{
    // A file:// URI for the new location of the file/folder being renamed.
    std::string new_uri;
    // A file:// URI for the original location of the file/folder being renamed.
    std::string old_uri;
};

template <>
struct glz::meta<FileRename> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents information on a file/folder delete.
// 
// @since 3.16.0
struct FileDelete
{
    // A file:// URI for the location of the file/folder being deleted.
    std::string uri;
};

template <>
struct glz::meta<FileDelete> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct MonikerOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<MonikerOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Type hierarchy options used during static registration.
// 
// @since 3.17.0
struct TypeHierarchyOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<TypeHierarchyOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.17.0
struct InlineValueContext
{
    // The stack frame (as a DAP Id) where the execution has stopped.
    int frame_id;
    // The document range where execution has stopped.
    // Typically the end position of the range denotes the line where the inline values are shown.
    Range stopped_location;
};

template <>
struct glz::meta<InlineValueContext> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provide inline value as text.
// 
// @since 3.17.0
struct InlineValueText
{
    // The document range for which the inline value applies.
    Range range;
    // The text of the inline value.
    std::string text;
};

template <>
struct glz::meta<InlineValueText> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provide inline value through a variable lookup.
// If only a range is specified, the variable name will be extracted from the underlying document.
// An optional variable name can be used to override the extracted name.
// 
// @since 3.17.0
struct InlineValueVariableLookup
{
    // How to perform the lookup.
    bool case_sensitive_lookup;
    // The document range for which the inline value applies.
    // The range is used to extract the variable name from the underlying document.
    Range range;
    // If specified the name of the variable to look up.
    std::optional<std::string> variable_name;
};

template <>
struct glz::meta<InlineValueVariableLookup> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provide an inline value through an expression evaluation.
// If only a range is specified, the expression will be extracted from the underlying document.
// An optional expression can be used to override the extracted expression.
// 
// @since 3.17.0
struct InlineValueEvaluatableExpression
{
    // If specified the expression overrides the extracted expression.
    std::optional<std::string> expression;
    // The document range for which the inline value applies.
    // The range is used to extract the evaluatable expression from the underlying document.
    Range range;
};

template <>
struct glz::meta<InlineValueEvaluatableExpression> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inline value options used during static registration.
// 
// @since 3.17.0
struct InlineValueOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<InlineValueOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// An inlay hint label part allows for interactive and composite labels
// of inlay hints.
// 
// @since 3.17.0
struct InlayHintLabelPart
{
    // An optional command for this label part.
    // 
    // Depending on the client capability `inlayHint.resolveSupport` clients
    // might resolve this property late using the resolve request.
    std::optional<Command> command;
    // An optional source code location that represents this
    // label part.
    // 
    // The editor will use this location for the hover and for code navigation
    // features: This part will become a clickable link that resolves to the
    // definition of the symbol at the given location (not necessarily the
    // location itself), it shows the hover that shows at the given location,
    // and it shows a context menu with further code navigation commands.
    // 
    // Depending on the client capability `inlayHint.resolveSupport` clients
    // might resolve this property late using the resolve request.
    std::optional<Location> location;
    // The tooltip text when you hover over this label part. Depending on
    // the client capability `inlayHint.resolveSupport` clients might resolve
    // this property late using the resolve request.
    std::optional<std::variant<std::string, MarkupContent>> tooltip;
    // The value of this label part.
    std::string value;
};

template <>
struct glz::meta<InlayHintLabelPart> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A `MarkupContent` literal represents a string value which content is interpreted base on its
// kind flag. Currently the protocol supports `plaintext` and `markdown` as markup kinds.
// 
// If the kind is `markdown` then the value can contain fenced code blocks like in GitHub issues.
// See https://help.github.com/articles/creating-and-highlighting-code-blocks/#syntax-highlighting
// 
// Here is an example how such a string can be constructed using JavaScript / TypeScript:
// ```ts
// let markdown: MarkdownContent = {
// kind: MarkupKind.Markdown,
// value: [
// '# Header',
// 'Some text',
// '```typescript',
// 'someCode();',
// '```'
// ].join('\n')
// };
// ```
// 
// *Please Note* that clients might sanitize the return markdown. A client could decide to
// remove HTML from the markdown to avoid script execution.
struct MarkupContent
{
    // The type of the Markup
    MarkupKind kind;
    // The content itself
    std::string value;
};

template <>
struct glz::meta<MarkupContent> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inlay hint options used during static registration.
// 
// @since 3.17.0
struct InlayHintOptions
{
    // The server provides support to resolve additional
    // information for an inlay hint item.
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<InlayHintOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A full diagnostic report with a set of related documents.
// 
// @since 3.17.0
struct RelatedFullDocumentDiagnosticReport
{
    // The actual items.
    std::vector<Diagnostic> items;
    // A full document diagnostic report.
    std::string kind;
    // Diagnostics of related documents. This information is useful
    // in programming languages where code in a file A can generate
    // diagnostics in a file B which A depends on. An example of
    // such a language is C/C++ where marco definitions in a file
    // a.cpp and result in errors in a header file b.hpp.
    // 
    // @since 3.17.0
    std::optional<std::unordered_map<std::string, std::variant<FullDocumentDiagnosticReport, UnchangedDocumentDiagnosticReport>>> related_documents;
    // An optional result id. If provided it will
    // be sent on the next diagnostic request for the
    // same document.
    std::optional<std::string> result_id;
};

template <>
struct glz::meta<RelatedFullDocumentDiagnosticReport> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// An unchanged diagnostic report with a set of related documents.
// 
// @since 3.17.0
struct RelatedUnchangedDocumentDiagnosticReport
{
    // A document diagnostic report indicating
    // no changes to the last result. A server can
    // only return `unchanged` if result ids are
    // provided.
    std::string kind;
    // Diagnostics of related documents. This information is useful
    // in programming languages where code in a file A can generate
    // diagnostics in a file B which A depends on. An example of
    // such a language is C/C++ where marco definitions in a file
    // a.cpp and result in errors in a header file b.hpp.
    // 
    // @since 3.17.0
    std::optional<std::unordered_map<std::string, std::variant<FullDocumentDiagnosticReport, UnchangedDocumentDiagnosticReport>>> related_documents;
    // A result id which will be sent on the next
    // diagnostic request for the same document.
    std::string result_id;
};

template <>
struct glz::meta<RelatedUnchangedDocumentDiagnosticReport> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A diagnostic report with a full set of problems.
// 
// @since 3.17.0
struct FullDocumentDiagnosticReport
{
    // The actual items.
    std::vector<Diagnostic> items;
    // A full document diagnostic report.
    std::string kind;
    // An optional result id. If provided it will
    // be sent on the next diagnostic request for the
    // same document.
    std::optional<std::string> result_id;
};

template <>
struct glz::meta<FullDocumentDiagnosticReport> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A diagnostic report indicating that the last returned
// report is still accurate.
// 
// @since 3.17.0
struct UnchangedDocumentDiagnosticReport
{
    // A document diagnostic report indicating
    // no changes to the last result. A server can
    // only return `unchanged` if result ids are
    // provided.
    std::string kind;
    // A result id which will be sent on the next
    // diagnostic request for the same document.
    std::string result_id;
};

template <>
struct glz::meta<UnchangedDocumentDiagnosticReport> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Diagnostic options.
// 
// @since 3.17.0
struct DiagnosticOptions
{
    // An optional identifier under which the diagnostics are
    // managed by the client.
    std::optional<std::string> identifier;
    // Whether the language has inter file dependencies meaning that
    // editing code in one file can result in a different diagnostic
    // set in another file. Inter file dependencies are common for
    // most programming languages and typically uncommon for linters.
    bool inter_file_dependencies;
    std::optional<bool> work_done_progress;
    // The server provides support for workspace diagnostics as well.
    bool workspace_diagnostics;
};

template <>
struct glz::meta<DiagnosticOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A previous result id in a workspace pull request.
// 
// @since 3.17.0
struct PreviousResultId
{
    // The URI for which the client knowns a
    // result id.
    std::string uri;
    // The value of the previous result id.
    std::string value;
};

template <>
struct glz::meta<PreviousResultId> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A notebook document.
// 
// @since 3.17.0
struct NotebookDocument
{
    // The cells of a notebook.
    std::vector<NotebookCell> cells;
    // Additional metadata stored with the notebook
    // document.
    // 
    // Note: should always be an object literal (e.g. LSPObject)
    std::optional<LSPObject> metadata;
    // The type of the notebook.
    std::string notebook_type;
    // The notebook document's uri.
    std::string uri;
    // The version number of this document (it will increase after each
    // change, including undo/redo).
    int version;
};

template <>
struct glz::meta<NotebookDocument> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// An item to transfer a text document from the client to the
// server.
struct TextDocumentItem
{
    // The text document's language identifier.
    LanguageKind language_id;
    // The content of the opened text document.
    std::string text;
    // The text document's uri.
    std::string uri;
    // The version number of this document (it will increase after each
    // change, including undo/redo).
    int version;
};

template <>
struct glz::meta<TextDocumentItem> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Options specific to a notebook plus its cells
// to be synced to the server.
// 
// If a selector provides a notebook document
// filter but no cell selector all cells of a
// matching notebook document will be synced.
// 
// If a selector provides no notebook document
// filter but only a cell selector all notebook
// document that contain at least one matching
// cell will be synced.
// 
// @since 3.17.0
struct NotebookDocumentSyncOptions
{
    // The notebooks to be synced
    std::vector<std::variant<NotebookDocumentFilterWithNotebook, NotebookDocumentFilterWithCells>> notebook_selector;
    // Whether save notification should be forwarded to
    // the server. Will only be honored if mode === `notebook`.
    std::optional<bool> save;
};

template <>
struct glz::meta<NotebookDocumentSyncOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A versioned notebook document identifier.
// 
// @since 3.17.0
struct VersionedNotebookDocumentIdentifier
{
    // The notebook document's uri.
    std::string uri;
    // The version number of this notebook document.
    int version;
};

template <>
struct glz::meta<VersionedNotebookDocumentIdentifier> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A change event for a notebook document.
// 
// @since 3.17.0
struct NotebookDocumentChangeEvent
{
    // Changes to cells
    std::optional<NotebookDocumentCellChanges> cells;
    // The changed meta data if any.
    // 
    // Note: should always be an object literal (e.g. LSPObject)
    std::optional<LSPObject> metadata;
};

template <>
struct glz::meta<NotebookDocumentChangeEvent> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A literal to identify a notebook document in the client.
// 
// @since 3.17.0
struct NotebookDocumentIdentifier
{
    // The notebook document's uri.
    std::string uri;
};

template <>
struct glz::meta<NotebookDocumentIdentifier> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provides information about the context in which an inline completion was requested.
// 
// @since 3.18.0
// @proposed
struct InlineCompletionContext
{
    // Provides information about the currently selected item in the autocomplete widget if it is visible.
    std::optional<SelectedCompletionInfo> selected_completion_info;
    // Describes how the inline completion was triggered.
    InlineCompletionTriggerKind trigger_kind;
};

template <>
struct glz::meta<InlineCompletionContext> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A string value used as a snippet is a template which allows to insert text
// and to control the editor cursor when insertion happens.
// 
// A snippet can define tab stops and placeholders with `$1`, `$2`
// and `${3:foo}`. `$0` defines the final tab stop, it defaults to
// the end of the snippet. Variables are defined with `$name` and
// `${name:default value}`.
// 
// @since 3.18.0
// @proposed
struct StringValue
{
    // The kind of string value.
    std::string kind;
    // The snippet string.
    std::string value;
};

template <>
struct glz::meta<StringValue> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inline completion options used during static registration.
// 
// @since 3.18.0
// @proposed
struct InlineCompletionOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<InlineCompletionOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Text document content provider options.
// 
// @since 3.18.0
// @proposed
struct TextDocumentContentOptions
{
    // The schemes for which the server provides content.
    std::vector<std::string> schemes;
};

template <>
struct glz::meta<TextDocumentContentOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// General parameters to register for a notification or to register a provider.
struct Registration
{
    // The id used to register the request. The id can be used to deregister
    // the request again.
    std::string id;
    // The method / capability to register for.
    std::string method;
    // Options necessary for the registration.
    std::optional<LSPAny> register_options;
};

template <>
struct glz::meta<Registration> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// General parameters to unregister a request or notification.
struct Unregistration
{
    // The id used to unregister the request or notification. Usually an id
    // provided during the register request.
    std::string id;
    // The method to unregister for.
    std::string method;
};

template <>
struct glz::meta<Unregistration> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The initialize parameters
struct _InitializeParams
{
    // The capabilities provided by the client (editor or tool)
    ClientCapabilities capabilities;
    // Information about the client
    // 
    // @since 3.15.0
    std::optional<ClientInfo> client_info;
    // User provided initialization options.
    std::optional<LSPAny> initialization_options;
    // The locale the client is currently showing the user interface
    // in. This must not necessarily be the locale of the operating
    // system.
    // 
    // Uses IETF language tags as the value's syntax
    // (See https://en.wikipedia.org/wiki/IETF_language_tag)
    // 
    // @since 3.16.0
    std::optional<std::string> locale;
    // The process Id of the parent process that started
    // the server.
    // 
    // Is `null` if the process has not been started by another process.
    // If the parent process is not alive then the server should exit.
    std::optional<int> process_id;
    // The rootPath of the workspace. Is null
    // if no folder is open.
    // 
    // @deprecated in favour of rootUri.
    std::optional<std::string> root_path;
    // The rootUri of the workspace. Is null if no
    // folder is open. If both `rootPath` and `rootUri` are set
    // `rootUri` wins.
    // 
    // @deprecated in favour of workspaceFolders.
    std::optional<std::string> root_uri;
    // The initial trace setting. If omitted trace is disabled ('off').
    std::optional<TraceValue> trace;
    // An optional token that a server can use to report work done progress.
    std::optional<ProgressToken> work_done_token;
};

template <>
struct glz::to<glz::JSON, _InitializeParams> {
    template <auto Opts>
    static void op(const _InitializeParams& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "capabilities", v.capabilities,
            "clientInfo", v.client_info,
            "initializationOptions", v.initialization_options,
            "locale", v.locale,
            "rootPath", v.root_path,
            "trace", v.trace,
            "workDoneToken", v.work_done_token,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.process_id.has_value()) {
            optional_fields.try_emplace("processId", *v.process_id);
        }
        if (v.root_uri.has_value()) {
            optional_fields.try_emplace("rootUri", *v.root_uri);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

struct WorkspaceFoldersInitializeParams
{
    // The workspace folders configured in the client when the server starts.
    // 
    // This property is only available if the client supports workspace folders.
    // It can be `null` if the client supports workspace folders but none are
    // configured.
    // 
    // @since 3.6.0
    std::optional<std::vector<WorkspaceFolder>> workspace_folders;
};

template <>
struct glz::meta<WorkspaceFoldersInitializeParams> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Defines the capabilities provided by a language
// server.
struct ServerCapabilities
{
    // The server provides call hierarchy support.
    // 
    // @since 3.16.0
    std::optional<std::variant<bool, CallHierarchyOptions, CallHierarchyRegistrationOptions>> call_hierarchy_provider;
    // The server provides code actions. CodeActionOptions may only be
    // specified if the client states that it supports
    // `codeActionLiteralSupport` in its initial `initialize` request.
    std::optional<std::variant<bool, CodeActionOptions>> code_action_provider;
    // The server provides code lens.
    std::optional<CodeLensOptions> code_lens_provider;
    // The server provides color provider support.
    std::optional<std::variant<bool, DocumentColorOptions, DocumentColorRegistrationOptions>> color_provider;
    // The server provides completion support.
    std::optional<CompletionOptions> completion_provider;
    // The server provides Goto Declaration support.
    std::optional<std::variant<bool, DeclarationOptions, DeclarationRegistrationOptions>> declaration_provider;
    // The server provides goto definition support.
    std::optional<std::variant<bool, DefinitionOptions>> definition_provider;
    // The server has support for pull model diagnostics.
    // 
    // @since 3.17.0
    std::optional<std::variant<DiagnosticOptions, DiagnosticRegistrationOptions>> diagnostic_provider;
    // The server provides document formatting.
    std::optional<std::variant<bool, DocumentFormattingOptions>> document_formatting_provider;
    // The server provides document highlight support.
    std::optional<std::variant<bool, DocumentHighlightOptions>> document_highlight_provider;
    // The server provides document link support.
    std::optional<DocumentLinkOptions> document_link_provider;
    // The server provides document formatting on typing.
    std::optional<DocumentOnTypeFormattingOptions> document_on_type_formatting_provider;
    // The server provides document range formatting.
    std::optional<std::variant<bool, DocumentRangeFormattingOptions>> document_range_formatting_provider;
    // The server provides document symbol support.
    std::optional<std::variant<bool, DocumentSymbolOptions>> document_symbol_provider;
    // The server provides execute command support.
    std::optional<ExecuteCommandOptions> execute_command_provider;
    // Experimental server capabilities.
    std::optional<LSPAny> experimental;
    // The server provides folding provider support.
    std::optional<std::variant<bool, FoldingRangeOptions, FoldingRangeRegistrationOptions>> folding_range_provider;
    // The server provides hover support.
    std::optional<std::variant<bool, HoverOptions>> hover_provider;
    // The server provides Goto Implementation support.
    std::optional<std::variant<bool, ImplementationOptions, ImplementationRegistrationOptions>> implementation_provider;
    // The server provides inlay hints.
    // 
    // @since 3.17.0
    std::optional<std::variant<bool, InlayHintOptions, InlayHintRegistrationOptions>> inlay_hint_provider;
    // Inline completion options used during static registration.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<std::variant<bool, InlineCompletionOptions>> inline_completion_provider;
    // The server provides inline values.
    // 
    // @since 3.17.0
    std::optional<std::variant<bool, InlineValueOptions, InlineValueRegistrationOptions>> inline_value_provider;
    // The server provides linked editing range support.
    // 
    // @since 3.16.0
    std::optional<std::variant<bool, LinkedEditingRangeOptions, LinkedEditingRangeRegistrationOptions>> linked_editing_range_provider;
    // The server provides moniker support.
    // 
    // @since 3.16.0
    std::optional<std::variant<bool, MonikerOptions, MonikerRegistrationOptions>> moniker_provider;
    // Defines how notebook documents are synced.
    // 
    // @since 3.17.0
    std::optional<std::variant<NotebookDocumentSyncOptions, NotebookDocumentSyncRegistrationOptions>> notebook_document_sync;
    // The position encoding the server picked from the encodings offered
    // by the client via the client capability `general.positionEncodings`.
    // 
    // If the client didn't provide any position encodings the only valid
    // value that a server can return is 'utf-16'.
    // 
    // If omitted it defaults to 'utf-16'.
    // 
    // @since 3.17.0
    std::optional<PositionEncodingKind> position_encoding;
    // The server provides find references support.
    std::optional<std::variant<bool, ReferenceOptions>> references_provider;
    // The server provides rename support. RenameOptions may only be
    // specified if the client states that it supports
    // `prepareSupport` in its initial `initialize` request.
    std::optional<std::variant<bool, RenameOptions>> rename_provider;
    // The server provides selection range support.
    std::optional<std::variant<bool, SelectionRangeOptions, SelectionRangeRegistrationOptions>> selection_range_provider;
    // The server provides semantic tokens support.
    // 
    // @since 3.16.0
    std::optional<std::variant<SemanticTokensOptions, SemanticTokensRegistrationOptions>> semantic_tokens_provider;
    // The server provides signature help support.
    std::optional<SignatureHelpOptions> signature_help_provider;
    // Defines how text documents are synced. Is either a detailed structure
    // defining each notification or for backwards compatibility the
    // TextDocumentSyncKind number.
    std::optional<std::variant<TextDocumentSyncOptions, TextDocumentSyncKind>> text_document_sync;
    // The server provides Goto Type Definition support.
    std::optional<std::variant<bool, TypeDefinitionOptions, TypeDefinitionRegistrationOptions>> type_definition_provider;
    // The server provides type hierarchy support.
    // 
    // @since 3.17.0
    std::optional<std::variant<bool, TypeHierarchyOptions, TypeHierarchyRegistrationOptions>> type_hierarchy_provider;
    // Workspace specific server capabilities.
    std::optional<WorkspaceOptions> workspace;
    // The server provides workspace symbol support.
    std::optional<std::variant<bool, WorkspaceSymbolOptions>> workspace_symbol_provider;
};

template <>
struct glz::meta<ServerCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Information about the server
// 
// @since 3.15.0
// @since 3.18.0 ServerInfo type name added.
struct ServerInfo
{
    // The name of the server as defined by the server.
    std::string name;
    // The server's version as defined by the server.
    std::optional<std::string> version;
};

template <>
struct glz::meta<ServerInfo> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A text document identifier to denote a specific version of a text document.
struct VersionedTextDocumentIdentifier
{
    // The text document's uri.
    std::string uri;
    // The version number of this document.
    int version;
};

template <>
struct glz::meta<VersionedTextDocumentIdentifier> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Save options.
struct SaveOptions
{
    // The client is supposed to include the content on save.
    std::optional<bool> include_text;
};

template <>
struct glz::meta<SaveOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// An event describing a file change.
struct FileEvent
{
    // The change type.
    FileChangeType type;
    // The file's uri.
    std::string uri;
};

template <>
struct glz::meta<FileEvent> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct FileSystemWatcher
{
    // The glob pattern to watch. See {@link GlobPattern glob pattern} for more detail.
    // 
    // @since 3.17.0 support for relative patterns.
    GlobPattern glob_pattern;
    // The kind of events of interest. If omitted it defaults
    // to WatchKind.Create | WatchKind.Change | WatchKind.Delete
    // which is 7.
    std::optional<WatchKind> kind;
};

template <>
struct glz::meta<FileSystemWatcher> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a diagnostic, such as a compiler error or warning. Diagnostic objects
// are only valid in the scope of a resource.
struct Diagnostic
{
    // The diagnostic's code, which usually appear in the user interface.
    std::optional<std::variant<int, std::string>> code;
    // An optional property to describe the error code.
    // Requires the code field (above) to be present/not null.
    // 
    // @since 3.16.0
    std::optional<CodeDescription> code_description;
    // A data entry field that is preserved between a `textDocument/publishDiagnostics`
    // notification and `textDocument/codeAction` request.
    // 
    // @since 3.16.0
    std::optional<LSPAny> data;
    // The diagnostic's message. It usually appears in the user interface
    std::string message;
    // The range at which the message applies
    Range range;
    // An array of related diagnostic information, e.g. when symbol-names within
    // a scope collide all definitions can be marked via this property.
    std::optional<std::vector<DiagnosticRelatedInformation>> related_information;
    // The diagnostic's severity. To avoid interpretation mismatches when a
    // server is used with different clients it is highly recommended that servers
    // always provide a severity value.
    std::optional<DiagnosticSeverity> severity;
    // A human-readable string describing the source of this
    // diagnostic, e.g. 'typescript' or 'super lint'. It usually
    // appears in the user interface.
    std::optional<std::string> source;
    // Additional metadata about the diagnostic.
    // 
    // @since 3.15.0
    std::optional<std::vector<DiagnosticTag>> tags;
};

template <>
struct glz::meta<Diagnostic> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Contains additional information about the context in which a completion request is triggered.
struct CompletionContext
{
    // The trigger character (a single character) that has trigger code complete.
    // Is undefined if `triggerKind !== CompletionTriggerKind.TriggerCharacter`
    std::optional<std::string> trigger_character;
    // How the completion was triggered.
    CompletionTriggerKind trigger_kind;
};

template <>
struct glz::meta<CompletionContext> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Additional details for a completion item label.
// 
// @since 3.17.0
struct CompletionItemLabelDetails
{
    // An optional string which is rendered less prominently after {@link CompletionItem.detail}. Should be used
    // for fully qualified names and file paths.
    std::optional<std::string> description;
    // An optional string which is rendered less prominently directly after {@link CompletionItem.label label},
    // without any spacing. Should be used for function signatures and type annotations.
    std::optional<std::string> detail;
};

template <>
struct glz::meta<CompletionItemLabelDetails> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A special text edit to provide an insert and a replace operation.
// 
// @since 3.16.0
struct InsertReplaceEdit
{
    // The range if the insert is requested
    Range insert;
    // The string to be inserted.
    std::string new_text;
    // The range if the replace is requested.
    Range replace;
};

template <>
struct glz::meta<InsertReplaceEdit> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// In many cases the items of an actual completion result share the same
// value for properties like `commitCharacters` or the range of a text
// edit. A completion list can therefore define item defaults which will
// be used if a completion item itself doesn't specify the value.
// 
// If a completion list specifies a default value and a completion item
// also specifies a corresponding value, the rules for combining these are
// defined by `applyKinds` (if the client supports it), defaulting to
// ApplyKind.Replace.
// 
// Servers are only allowed to return default values if the client
// signals support for this via the `completionList.itemDefaults`
// capability.
// 
// @since 3.17.0
struct CompletionItemDefaults
{
    // A default commit character set.
    // 
    // @since 3.17.0
    std::optional<std::vector<std::string>> commit_characters;
    // A default data value.
    // 
    // @since 3.17.0
    std::optional<LSPAny> data;
    // A default edit range.
    // 
    // @since 3.17.0
    std::optional<std::variant<Range, EditRangeWithInsertReplace>> edit_range;
    // A default insert text format.
    // 
    // @since 3.17.0
    std::optional<InsertTextFormat> insert_text_format;
    // A default insert text mode.
    // 
    // @since 3.17.0
    std::optional<InsertTextMode> insert_text_mode;
};

template <>
struct glz::meta<CompletionItemDefaults> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Specifies how fields from a completion item should be combined with those
// from `completionList.itemDefaults`.
// 
// If unspecified, all fields will be treated as ApplyKind.Replace.
// 
// If a field's value is ApplyKind.Replace, the value from a completion item (if
// provided and not `null`) will always be used instead of the value from
// `completionItem.itemDefaults`.
// 
// If a field's value is ApplyKind.Merge, the values will be merged using the rules
// defined against each field below.
// 
// Servers are only allowed to return `applyKind` if the client
// signals support for this via the `completionList.applyKindSupport`
// capability.
// 
// @since 3.18.0
struct CompletionItemApplyKinds
{
    // Specifies whether commitCharacters on a completion will replace or be
    // merged with those in `completionList.itemDefaults.commitCharacters`.
    // 
    // If ApplyKind.Replace, the commit characters from the completion item will
    // always be used unless not provided, in which case those from
    // `completionList.itemDefaults.commitCharacters` will be used. An
    // empty list can be used if a completion item does not have any commit
    // characters and also should not use those from
    // `completionList.itemDefaults.commitCharacters`.
    // 
    // If ApplyKind.Merge the commitCharacters for the completion will be the
    // union of all values in both `completionList.itemDefaults.commitCharacters`
    // and the completion's own `commitCharacters`.
    // 
    // @since 3.18.0
    std::optional<ApplyKind> commit_characters;
    // Specifies whether the `data` field on a completion will replace or
    // be merged with data from `completionList.itemDefaults.data`.
    // 
    // If ApplyKind.Replace, the data from the completion item will be used if
    // provided (and not `null`), otherwise
    // `completionList.itemDefaults.data` will be used. An empty object can
    // be used if a completion item does not have any data but also should
    // not use the value from `completionList.itemDefaults.data`.
    // 
    // If ApplyKind.Merge, a shallow merge will be performed between
    // `completionList.itemDefaults.data` and the completion's own data
    // using the following rules:
    // 
    // - If a completion's `data` field is not provided (or `null`), the
    // entire `data` field from `completionList.itemDefaults.data` will be
    // used as-is.
    // - If a completion's `data` field is provided, each field will
    // overwrite the field of the same name in
    // `completionList.itemDefaults.data` but no merging of nested fields
    // within that value will occur.
    // 
    // @since 3.18.0
    std::optional<ApplyKind> data;
};

template <>
struct glz::meta<CompletionItemApplyKinds> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Completion options.
struct CompletionOptions
{
    // The list of all possible characters that commit a completion. This field can be used
    // if clients don't support individual commit characters per completion item. See
    // `ClientCapabilities.textDocument.completion.completionItem.commitCharactersSupport`
    // 
    // If a server provides both `allCommitCharacters` and commit characters on an individual
    // completion item the ones on the completion item win.
    // 
    // @since 3.2.0
    std::optional<std::vector<std::string>> all_commit_characters;
    // The server supports the following `CompletionItem` specific
    // capabilities.
    // 
    // @since 3.17.0
    std::optional<ServerCompletionItemOptions> completion_item;
    // The server provides support to resolve additional
    // information for a completion item.
    std::optional<bool> resolve_provider;
    // Most tools trigger completion request automatically without explicitly requesting
    // it using a keyboard shortcut (e.g. Ctrl+Space). Typically they do so when the user
    // starts to type an identifier. For example if the user types `c` in a JavaScript file
    // code complete will automatically pop up present `console` besides others as a
    // completion item. Characters that make up identifiers don't need to be listed here.
    // 
    // If code complete should automatically be trigger on characters not being valid inside
    // an identifier (for example `.` in JavaScript) list them in `triggerCharacters`.
    std::optional<std::vector<std::string>> trigger_characters;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<CompletionOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Hover options.
struct HoverOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<HoverOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Additional information about the context in which a signature help request was triggered.
// 
// @since 3.15.0
struct SignatureHelpContext
{
    // The currently active `SignatureHelp`.
    // 
    // The `activeSignatureHelp` has its `SignatureHelp.activeSignature` field updated based on
    // the user navigating through available signatures.
    std::optional<SignatureHelp> active_signature_help;
    // `true` if signature help was already showing when it was triggered.
    // 
    // Retriggers occurs when the signature help is already active and can be caused by actions such as
    // typing a trigger character, a cursor move, or document content changes.
    bool is_retrigger;
    // Character that caused signature help to be triggered.
    // 
    // This is undefined when `triggerKind !== SignatureHelpTriggerKind.TriggerCharacter`
    std::optional<std::string> trigger_character;
    // Action that caused signature help to be triggered.
    SignatureHelpTriggerKind trigger_kind;
};

template <>
struct glz::meta<SignatureHelpContext> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents the signature of something callable. A signature
// can have a label, like a function-name, a doc-comment, and
// a set of parameters.
struct SignatureInformation
{
    // The index of the active parameter.
    // 
    // If `null`, no parameter of the signature is active (for example a named
    // argument that does not match any declared parameters). This is only valid
    // if the client specifies the client capability
    // `textDocument.signatureHelp.noActiveParameterSupport === true`
    // 
    // If provided (or `null`), this is used in place of
    // `SignatureHelp.activeParameter`.
    // 
    // @since 3.16.0
    std::optional<unsigned int> active_parameter;
    // The human-readable doc-comment of this signature. Will be shown
    // in the UI but can be omitted.
    std::optional<std::variant<std::string, MarkupContent>> documentation;
    // The label of this signature. Will be shown in
    // the UI.
    std::string label;
    // The parameters of this signature.
    std::optional<std::vector<ParameterInformation>> parameters;
};

template <>
struct glz::meta<SignatureInformation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Server Capabilities for a {@link SignatureHelpRequest}.
struct SignatureHelpOptions
{
    // List of characters that re-trigger signature help.
    // 
    // These trigger characters are only active when signature help is already showing. All trigger characters
    // are also counted as re-trigger characters.
    // 
    // @since 3.15.0
    std::optional<std::vector<std::string>> retrigger_characters;
    // List of characters that trigger signature help automatically.
    std::optional<std::vector<std::string>> trigger_characters;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<SignatureHelpOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Server Capabilities for a {@link DefinitionRequest}.
struct DefinitionOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DefinitionOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Value-object that contains additional information when
// requesting references.
struct ReferenceContext
{
    // Include the declaration of the current symbol.
    bool include_declaration;
};

template <>
struct glz::meta<ReferenceContext> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Reference options.
struct ReferenceOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<ReferenceOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link DocumentHighlightRequest}.
struct DocumentHighlightOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DocumentHighlightOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A base for all symbol information.
struct BaseSymbolInformation
{
    // The name of the symbol containing this symbol. This information is for
    // user interface purposes (e.g. to render a qualifier in the user interface
    // if necessary). It can't be used to re-infer a hierarchy for the document
    // symbols.
    std::optional<std::string> container_name;
    // The kind of this symbol.
    SymbolKind kind;
    // The name of this symbol.
    std::string name;
    // Tags for this symbol.
    // 
    // @since 3.16.0
    std::optional<std::vector<SymbolTag>> tags;
};

template <>
struct glz::meta<BaseSymbolInformation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link DocumentSymbolRequest}.
struct DocumentSymbolOptions
{
    // A human-readable string that is shown when multiple outlines trees
    // are shown for the same document.
    // 
    // @since 3.16.0
    std::optional<std::string> label;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DocumentSymbolOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Contains additional diagnostic information about the context in which
// a {@link CodeActionProvider.provideCodeActions code action} is run.
struct CodeActionContext
{
    // An array of diagnostics known on the client side overlapping the range provided to the
    // `textDocument/codeAction` request. They are provided so that the server knows which
    // errors are currently presented to the user for the given range. There is no guarantee
    // that these accurately reflect the error state of the resource. The primary parameter
    // to compute code actions is the provided range.
    std::vector<Diagnostic> diagnostics;
    // Requested kind of actions to return.
    // 
    // Actions not of this kind are filtered out by the client before being shown. So servers
    // can omit computing them.
    std::optional<std::vector<CodeActionKind>> only;
    // The reason why code actions were requested.
    // 
    // @since 3.17.0
    std::optional<CodeActionTriggerKind> trigger_kind;
};

template <>
struct glz::meta<CodeActionContext> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Captures why the code action is currently disabled.
// 
// @since 3.18.0
struct CodeActionDisabled
{
    // Human readable description of why the code action is currently disabled.
    // 
    // This is displayed in the code actions UI.
    std::string reason;
};

template <>
struct glz::meta<CodeActionDisabled> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link CodeActionRequest}.
struct CodeActionOptions
{
    // CodeActionKinds that this server may return.
    // 
    // The list of kinds may be generic, such as `CodeActionKind.Refactor`, or the server
    // may list out every specific kind they provide.
    std::optional<std::vector<CodeActionKind>> code_action_kinds;
    // Static documentation for a class of code actions.
    // 
    // Documentation from the provider should be shown in the code actions menu if either:
    // 
    // - Code actions of `kind` are requested by the editor. In this case, the editor will show the documentation that
    // most closely matches the requested code action kind. For example, if a provider has documentation for
    // both `Refactor` and `RefactorExtract`, when the user requests code actions for `RefactorExtract`,
    // the editor will use the documentation for `RefactorExtract` instead of the documentation for `Refactor`.
    // 
    // - Any code actions of `kind` are returned by the provider.
    // 
    // At most one documentation entry should be shown per provider.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<std::vector<CodeActionKindDocumentation>> documentation;
    // The server provides support to resolve additional
    // information for a code action.
    // 
    // @since 3.16.0
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<CodeActionOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Location with only uri and does not include range.
// 
// @since 3.18.0
struct LocationUriOnly
{
    std::string uri;
};

template <>
struct glz::meta<LocationUriOnly> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Server capabilities for a {@link WorkspaceSymbolRequest}.
struct WorkspaceSymbolOptions
{
    // The server provides support to resolve additional
    // information for a workspace symbol.
    // 
    // @since 3.17.0
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<WorkspaceSymbolOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Code Lens provider options of a {@link CodeLensRequest}.
struct CodeLensOptions
{
    // Code lens has a resolve provider as well.
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<CodeLensOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link DocumentLinkRequest}.
struct DocumentLinkOptions
{
    // Document links have a resolve provider as well.
    std::optional<bool> resolve_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DocumentLinkOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Value-object describing what options formatting should use.
struct FormattingOptions
{
    // Insert a newline character at the end of the file if one does not exist.
    // 
    // @since 3.15.0
    std::optional<bool> insert_final_newline;
    // Prefer spaces over tabs.
    bool insert_spaces;
    // Size of a tab in spaces.
    unsigned int tab_size;
    // Trim all newlines after the final newline at the end of the file.
    // 
    // @since 3.15.0
    std::optional<bool> trim_final_newlines;
    // Trim trailing whitespace on a line.
    // 
    // @since 3.15.0
    std::optional<bool> trim_trailing_whitespace;
};

template <>
struct glz::meta<FormattingOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link DocumentFormattingRequest}.
struct DocumentFormattingOptions
{
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DocumentFormattingOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link DocumentRangeFormattingRequest}.
struct DocumentRangeFormattingOptions
{
    // Whether the server supports formatting multiple ranges at once.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> ranges_support;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<DocumentRangeFormattingOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link DocumentOnTypeFormattingRequest}.
struct DocumentOnTypeFormattingOptions
{
    // A character on which formatting should be triggered, like `{`.
    std::string first_trigger_character;
    // More trigger characters.
    std::optional<std::vector<std::string>> more_trigger_character;
};

template <>
struct glz::meta<DocumentOnTypeFormattingOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Provider options for a {@link RenameRequest}.
struct RenameOptions
{
    // Renames should be checked and tested before being executed.
    // 
    // @since version 3.12.0
    std::optional<bool> prepare_provider;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<RenameOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct PrepareRenamePlaceholder
{
    std::string placeholder;
    Range range;
};

template <>
struct glz::meta<PrepareRenamePlaceholder> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct PrepareRenameDefaultBehavior
{
    bool default_behavior;
};

template <>
struct glz::meta<PrepareRenameDefaultBehavior> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The server capabilities of a {@link ExecuteCommandRequest}.
struct ExecuteCommandOptions
{
    // The commands to be executed on the server
    std::vector<std::string> commands;
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<ExecuteCommandOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Additional data about a workspace edit.
// 
// @since 3.18.0
// @proposed
struct WorkspaceEditMetadata
{
    // Signal to the editor that this edit is a refactoring.
    std::optional<bool> is_refactoring;
};

template <>
struct glz::meta<WorkspaceEditMetadata> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensLegend
{
    // The token modifiers a server uses.
    std::vector<std::string> token_modifiers;
    // The token types a server uses.
    std::vector<std::string> token_types;
};

template <>
struct glz::meta<SemanticTokensLegend> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Semantic tokens options to support deltas for full documents
// 
// @since 3.18.0
struct SemanticTokensFullDelta
{
    // The server supports deltas for full documents.
    std::optional<bool> delta;
};

template <>
struct glz::meta<SemanticTokensFullDelta> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A text document identifier to optionally denote a specific version of a text document.
struct OptionalVersionedTextDocumentIdentifier
{
    // The text document's uri.
    std::string uri;
    // The version number of this document. If a versioned text document identifier
    // is sent from the server to the client and the file is not open in the editor
    // (the server has not received an open notification before) the server can send
    // `null` to indicate that the version is unknown and the content on disk is the
    // truth (as specified with document content ownership).
    std::optional<int> version;
};

template <>
struct glz::to<glz::JSON, OptionalVersionedTextDocumentIdentifier> {
    template <auto Opts>
    static void op(const OptionalVersionedTextDocumentIdentifier& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "uri", v.uri,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.version.has_value()) {
            optional_fields.try_emplace("version", *v.version);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// A special text edit with an additional change annotation.
// 
// @since 3.16.0.
struct AnnotatedTextEdit
{
    // The actual identifier of the change annotation
    ChangeAnnotationIdentifier annotation_id;
    // The string to be inserted. For delete operations use an
    // empty string.
    std::string new_text;
    // The range of the text document to be manipulated. To insert
    // text into a document create a range where start === end.
    Range range;
};

template <>
struct glz::meta<AnnotatedTextEdit> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// An interactive text edit.
// 
// @since 3.18.0
// @proposed
struct SnippetTextEdit
{
    // The actual identifier of the snippet edit.
    std::optional<ChangeAnnotationIdentifier> annotation_id;
    // The range of the text document to be manipulated.
    Range range;
    // The snippet to be inserted.
    StringValue snippet;
};

template <>
struct glz::meta<SnippetTextEdit> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A generic resource operation.
struct ResourceOperation
{
    // An optional annotation identifier describing the operation.
    // 
    // @since 3.16.0
    std::optional<ChangeAnnotationIdentifier> annotation_id;
    // The resource operation kind.
    std::string kind;
};

template <>
struct glz::meta<ResourceOperation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Options to create a file.
struct CreateFileOptions
{
    // Ignore if exists.
    std::optional<bool> ignore_if_exists;
    // Overwrite existing file. Overwrite wins over `ignoreIfExists`
    std::optional<bool> overwrite;
};

template <>
struct glz::meta<CreateFileOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Rename file options
struct RenameFileOptions
{
    // Ignores if target exists.
    std::optional<bool> ignore_if_exists;
    // Overwrite target if existing. Overwrite wins over `ignoreIfExists`
    std::optional<bool> overwrite;
};

template <>
struct glz::meta<RenameFileOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Delete file options
struct DeleteFileOptions
{
    // Ignore the operation if the file doesn't exist.
    std::optional<bool> ignore_if_not_exists;
    // Delete the content recursively if a folder is denoted.
    std::optional<bool> recursive;
};

template <>
struct glz::meta<DeleteFileOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A pattern to describe in which file operation requests or notifications
// the server is interested in receiving.
// 
// @since 3.16.0
struct FileOperationPattern
{
    // The glob pattern to match. Glob patterns can have the following syntax:
    // - `*` to match one or more characters in a path segment
    // - `?` to match on one character in a path segment
    // - `**` to match any number of path segments, including none
    // - `{}` to group sub patterns into an OR expression. (e.g. `**​/*.{ts,js}` matches all TypeScript and JavaScript files)
    // - `[]` to declare a range of characters to match in a path segment (e.g., `example.[0-9]` to match on `example.0`, `example.1`, …)
    // - `[!...]` to negate a range of characters to match in a path segment (e.g., `example.[!0-9]` to match on `example.a`, `example.b`, but not `example.0`)
    std::string glob;
    // Whether to match files or folders with this pattern.
    // 
    // Matches both if undefined.
    std::optional<FileOperationPatternKind> matches;
    // Additional options used during matching.
    std::optional<FileOperationPatternOptions> options;
};

template <>
struct glz::meta<FileOperationPattern> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A full document diagnostic report for a workspace diagnostic result.
// 
// @since 3.17.0
struct WorkspaceFullDocumentDiagnosticReport
{
    // The actual items.
    std::vector<Diagnostic> items;
    // A full document diagnostic report.
    std::string kind;
    // An optional result id. If provided it will
    // be sent on the next diagnostic request for the
    // same document.
    std::optional<std::string> result_id;
    // The URI for which diagnostic information is reported.
    std::string uri;
    // The version number for which the diagnostics are reported.
    // If the document is not marked as open `null` can be provided.
    std::optional<int> version;
};

template <>
struct glz::to<glz::JSON, WorkspaceFullDocumentDiagnosticReport> {
    template <auto Opts>
    static void op(const WorkspaceFullDocumentDiagnosticReport& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "items", v.items,
            "kind", v.kind,
            "resultId", v.result_id,
            "uri", v.uri,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.version.has_value()) {
            optional_fields.try_emplace("version", *v.version);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// An unchanged document diagnostic report for a workspace diagnostic result.
// 
// @since 3.17.0
struct WorkspaceUnchangedDocumentDiagnosticReport
{
    // A document diagnostic report indicating
    // no changes to the last result. A server can
    // only return `unchanged` if result ids are
    // provided.
    std::string kind;
    // A result id which will be sent on the next
    // diagnostic request for the same document.
    std::string result_id;
    // The URI for which diagnostic information is reported.
    std::string uri;
    // The version number for which the diagnostics are reported.
    // If the document is not marked as open `null` can be provided.
    std::optional<int> version;
};

template <>
struct glz::to<glz::JSON, WorkspaceUnchangedDocumentDiagnosticReport> {
    template <auto Opts>
    static void op(const WorkspaceUnchangedDocumentDiagnosticReport& v, is_context auto&& ctx, auto&& buffer, auto&& iter) noexcept {
        auto obj = glz::obj{
            "kind", v.kind,
            "resultId", v.result_id,
            "uri", v.uri,
        };
        std::map<std::string_view, glz::json_t> optional_fields;
        if (v.version.has_value()) {
            optional_fields.try_emplace("version", *v.version);
        }
        auto merged = glz::merge{ obj, optional_fields };
        serialize<JSON>::op<Opts>(merged, ctx, buffer, iter);
    }
};

// A notebook cell.
// 
// A cell's document URI must be unique across ALL notebook
// cells and can therefore be used to uniquely identify a
// notebook cell or the cell's text document.
// 
// @since 3.17.0
struct NotebookCell
{
    // The URI of the cell's text document
    // content.
    std::string document;
    // Additional execution summary information
    // if supported by the client.
    std::optional<ExecutionSummary> execution_summary;
    // The cell's kind
    NotebookCellKind kind;
    // Additional metadata stored with the cell.
    // 
    // Note: should always be an object literal (e.g. LSPObject)
    std::optional<LSPObject> metadata;
};

template <>
struct glz::meta<NotebookCell> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct NotebookDocumentFilterWithNotebook
{
    // The cells of the matching notebook to be synced.
    std::optional<std::vector<NotebookCellLanguage>> cells;
    // The notebook to be synced If a string
    // value is provided it matches against the
    // notebook type. '*' matches every notebook.
    std::variant<std::string, NotebookDocumentFilter> notebook;
};

template <>
struct glz::meta<NotebookDocumentFilterWithNotebook> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct NotebookDocumentFilterWithCells
{
    // The cells of the matching notebook to be synced.
    std::vector<NotebookCellLanguage> cells;
    // The notebook to be synced If a string
    // value is provided it matches against the
    // notebook type. '*' matches every notebook.
    std::optional<std::variant<std::string, NotebookDocumentFilter>> notebook;
};

template <>
struct glz::meta<NotebookDocumentFilterWithCells> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Cell changes to a notebook document.
// 
// @since 3.18.0
struct NotebookDocumentCellChanges
{
    // Changes to notebook cells properties like its
    // kind, execution summary or metadata.
    std::optional<std::vector<NotebookCell>> data;
    // Changes to the cell structure to add or
    // remove cells.
    std::optional<NotebookDocumentCellChangeStructure> structure;
    // Changes to the text content of notebook cells.
    std::optional<std::vector<NotebookDocumentCellContentChanges>> text_content;
};

template <>
struct glz::meta<NotebookDocumentCellChanges> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Describes the currently selected completion item.
// 
// @since 3.18.0
// @proposed
struct SelectedCompletionInfo
{
    // The range that will be replaced if this completion item is accepted.
    Range range;
    // The text the range will be replaced with if this completion is accepted.
    std::string text;
};

template <>
struct glz::meta<SelectedCompletionInfo> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Information about the client
// 
// @since 3.15.0
// @since 3.18.0 ClientInfo type name added.
struct ClientInfo
{
    // The name of the client as defined by the client.
    std::string name;
    // The client's version as defined by the client.
    std::optional<std::string> version;
};

template <>
struct glz::meta<ClientInfo> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Defines the capabilities provided by the client.
struct ClientCapabilities
{
    // Experimental client capabilities.
    std::optional<LSPAny> experimental;
    // General client capabilities.
    // 
    // @since 3.16.0
    std::optional<GeneralClientCapabilities> general;
    // Capabilities specific to the notebook document support.
    // 
    // @since 3.17.0
    std::optional<NotebookDocumentClientCapabilities> notebook_document;
    // Text document specific client capabilities.
    std::optional<TextDocumentClientCapabilities> text_document;
    // Window specific client capabilities.
    std::optional<WindowClientCapabilities> window;
    // Workspace specific client capabilities.
    std::optional<WorkspaceClientCapabilities> workspace;
};

template <>
struct glz::meta<ClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct TextDocumentSyncOptions
{
    // Change notifications are sent to the server. See TextDocumentSyncKind.None, TextDocumentSyncKind.Full
    // and TextDocumentSyncKind.Incremental. If omitted it defaults to TextDocumentSyncKind.None.
    std::optional<TextDocumentSyncKind> change;
    // Open and close notifications are sent to the server. If omitted open close notification should not
    // be sent.
    std::optional<bool> open_close;
    // If present save notifications are sent to the server. If omitted the notification should not be
    // sent.
    std::optional<std::variant<bool, SaveOptions>> save;
    // If present will save notifications are sent to the server. If omitted the notification should not be
    // sent.
    std::optional<bool> will_save;
    // If present will save wait until requests are sent to the server. If omitted the request should not be
    // sent.
    std::optional<bool> will_save_wait_until;
};

template <>
struct glz::meta<TextDocumentSyncOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Defines workspace specific capabilities of the server.
// 
// @since 3.18.0
struct WorkspaceOptions
{
    // The server is interested in notifications/requests for operations on files.
    // 
    // @since 3.16.0
    std::optional<FileOperationOptions> file_operations;
    // The server supports the `workspace/textDocumentContent` request.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<std::variant<TextDocumentContentOptions, TextDocumentContentRegistrationOptions>> text_document_content;
    // The server supports workspace folder.
    // 
    // @since 3.6.0
    std::optional<WorkspaceFoldersServerCapabilities> workspace_folders;
};

template <>
struct glz::meta<WorkspaceOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct TextDocumentContentChangePartial
{
    // The range of the document that changed.
    Range range;
    // The optional length of the range that got replaced.
    // 
    // @deprecated use range instead.
    std::optional<unsigned int> range_length;
    // The new text for the provided range.
    std::string text;
};

template <>
struct glz::meta<TextDocumentContentChangePartial> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct TextDocumentContentChangeWholeDocument
{
    // The new text of the whole document.
    std::string text;
};

template <>
struct glz::meta<TextDocumentContentChangeWholeDocument> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Structure to capture a description for an error code.
// 
// @since 3.16.0
struct CodeDescription
{
    // An URI to open with more information about the diagnostic error.
    std::string href;
};

template <>
struct glz::meta<CodeDescription> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a related message and source code location for a diagnostic. This should be
// used to point to code locations that cause or related to a diagnostics, e.g when duplicating
// a symbol in a scope.
struct DiagnosticRelatedInformation
{
    // The location of this related diagnostic information.
    Location location;
    // The message of this related diagnostic information.
    std::string message;
};

template <>
struct glz::meta<DiagnosticRelatedInformation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Edit range variant that includes ranges for insert and replace operations.
// 
// @since 3.18.0
struct EditRangeWithInsertReplace
{
    Range insert;
    Range replace;
};

template <>
struct glz::meta<EditRangeWithInsertReplace> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ServerCompletionItemOptions
{
    // The server has support for completion item label
    // details (see also `CompletionItemLabelDetails`) when
    // receiving a completion item in a resolve call.
    // 
    // @since 3.17.0
    std::optional<bool> label_details_support;
};

template <>
struct glz::meta<ServerCompletionItemOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
// @deprecated use MarkupContent instead.
struct MarkedStringWithLanguage
{
    std::string language;
    std::string value;
};

template <>
struct glz::meta<MarkedStringWithLanguage> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Represents a parameter of a callable-signature. A parameter can
// have a label and a doc-comment.
struct ParameterInformation
{
    // The human-readable doc-comment of this parameter. Will be shown
    // in the UI but can be omitted.
    std::optional<std::variant<std::string, MarkupContent>> documentation;
    // The label of this parameter information.
    // 
    // Either a string or an inclusive start and exclusive end offsets within its containing
    // signature label. (see SignatureInformation.label). The offsets are based on a UTF-16
    // string representation as `Position` and `Range` does.
    // 
    // To avoid ambiguities a server should use the [start, end] offset value instead of using
    // a substring. Whether a client support this is controlled via `labelOffsetSupport` client
    // capability.
    // 
    // *Note*: a label of type string should be a substring of its containing signature label.
    // Its intended use case is to highlight the parameter label part in the `SignatureInformation.label`.
    std::variant<std::string, std::tuple<unsigned int, unsigned int>> label;
};

template <>
struct glz::meta<ParameterInformation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Documentation for a class of code actions.
// 
// @since 3.18.0
// @proposed
struct CodeActionKindDocumentation
{
    // Command that is ued to display the documentation to the user.
    // 
    // The title of this documentation code action is taken from {@linkcode Command.title}
    Command command;
    // The kind of the code action being documented.
    // 
    // If the kind is generic, such as `CodeActionKind.Refactor`, the documentation will be shown whenever any
    // refactorings are returned. If the kind if more specific, such as `CodeActionKind.RefactorExtract`, the
    // documentation will only be shown when extract refactoring code actions are returned.
    CodeActionKind kind;
};

template <>
struct glz::meta<CodeActionKindDocumentation> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A notebook cell text document filter denotes a cell text
// document by different properties.
// 
// @since 3.17.0
struct NotebookCellTextDocumentFilter
{
    // A language id like `python`.
    // 
    // Will be matched against the language id of the
    // notebook cell document. '*' matches every language.
    std::optional<std::string> language;
    // A filter that matches against the notebook
    // containing the notebook cell. If a string
    // value is provided it matches against the
    // notebook type. '*' matches every notebook.
    std::variant<std::string, NotebookDocumentFilter> notebook;
};

template <>
struct glz::meta<NotebookCellTextDocumentFilter> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Matching options for the file operation pattern.
// 
// @since 3.16.0
struct FileOperationPatternOptions
{
    // The pattern should be matched ignoring casing.
    std::optional<bool> ignore_case;
};

template <>
struct glz::meta<FileOperationPatternOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct ExecutionSummary
{
    // A strict monotonically increasing value
    // indicating the execution order of a cell
    // inside a notebook.
    unsigned int execution_order;
    // Whether the execution was successful or
    // not if known by the client.
    std::optional<bool> success;
};

template <>
struct glz::meta<ExecutionSummary> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct NotebookCellLanguage
{
    std::string language;
};

template <>
struct glz::meta<NotebookCellLanguage> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Structural changes to cells in a notebook document.
// 
// @since 3.18.0
struct NotebookDocumentCellChangeStructure
{
    // The change to the cell array.
    NotebookCellArrayChange array;
    // Additional closed cell text documents.
    std::optional<std::vector<TextDocumentIdentifier>> did_close;
    // Additional opened cell text documents.
    std::optional<std::vector<TextDocumentItem>> did_open;
};

template <>
struct glz::meta<NotebookDocumentCellChangeStructure> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Content changes to a cell in a notebook document.
// 
// @since 3.18.0
struct NotebookDocumentCellContentChanges
{
    std::vector<TextDocumentContentChangeEvent> changes;
    VersionedTextDocumentIdentifier document;
};

template <>
struct glz::meta<NotebookDocumentCellContentChanges> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Workspace specific client capabilities.
struct WorkspaceClientCapabilities
{
    // The client supports applying batch edits
    // to the workspace by supporting the request
    // 'workspace/applyEdit'
    std::optional<bool> apply_edit;
    // Capabilities specific to the code lens requests scoped to the
    // workspace.
    // 
    // @since 3.16.0.
    std::optional<CodeLensWorkspaceClientCapabilities> code_lens;
    // The client supports `workspace/configuration` requests.
    // 
    // @since 3.6.0
    std::optional<bool> configuration;
    // Capabilities specific to the diagnostic requests scoped to the
    // workspace.
    // 
    // @since 3.17.0.
    std::optional<DiagnosticWorkspaceClientCapabilities> diagnostics;
    // Capabilities specific to the `workspace/didChangeConfiguration` notification.
    std::optional<DidChangeConfigurationClientCapabilities> did_change_configuration;
    // Capabilities specific to the `workspace/didChangeWatchedFiles` notification.
    std::optional<DidChangeWatchedFilesClientCapabilities> did_change_watched_files;
    // Capabilities specific to the `workspace/executeCommand` request.
    std::optional<ExecuteCommandClientCapabilities> execute_command;
    // The client has support for file notifications/requests for user operations on files.
    // 
    // Since 3.16.0
    std::optional<FileOperationClientCapabilities> file_operations;
    // Capabilities specific to the folding range requests scoped to the workspace.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<FoldingRangeWorkspaceClientCapabilities> folding_range;
    // Capabilities specific to the inlay hint requests scoped to the
    // workspace.
    // 
    // @since 3.17.0.
    std::optional<InlayHintWorkspaceClientCapabilities> inlay_hint;
    // Capabilities specific to the inline values requests scoped to the
    // workspace.
    // 
    // @since 3.17.0.
    std::optional<InlineValueWorkspaceClientCapabilities> inline_value;
    // Capabilities specific to the semantic token requests scoped to the
    // workspace.
    // 
    // @since 3.16.0.
    std::optional<SemanticTokensWorkspaceClientCapabilities> semantic_tokens;
    // Capabilities specific to the `workspace/symbol` request.
    std::optional<WorkspaceSymbolClientCapabilities> symbol;
    // Capabilities specific to the `workspace/textDocumentContent` request.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<TextDocumentContentClientCapabilities> text_document_content;
    // Capabilities specific to `WorkspaceEdit`s.
    std::optional<WorkspaceEditClientCapabilities> workspace_edit;
    // The client has support for workspace folders.
    // 
    // @since 3.6.0
    std::optional<bool> workspace_folders;
};

template <>
struct glz::meta<WorkspaceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Text document specific client capabilities.
struct TextDocumentClientCapabilities
{
    // Capabilities specific to the various call hierarchy requests.
    // 
    // @since 3.16.0
    std::optional<CallHierarchyClientCapabilities> call_hierarchy;
    // Capabilities specific to the `textDocument/codeAction` request.
    std::optional<CodeActionClientCapabilities> code_action;
    // Capabilities specific to the `textDocument/codeLens` request.
    std::optional<CodeLensClientCapabilities> code_lens;
    // Capabilities specific to the `textDocument/documentColor` and the
    // `textDocument/colorPresentation` request.
    // 
    // @since 3.6.0
    std::optional<DocumentColorClientCapabilities> color_provider;
    // Capabilities specific to the `textDocument/completion` request.
    std::optional<CompletionClientCapabilities> completion;
    // Capabilities specific to the `textDocument/declaration` request.
    // 
    // @since 3.14.0
    std::optional<DeclarationClientCapabilities> declaration;
    // Capabilities specific to the `textDocument/definition` request.
    std::optional<DefinitionClientCapabilities> definition;
    // Capabilities specific to the diagnostic pull model.
    // 
    // @since 3.17.0
    std::optional<DiagnosticClientCapabilities> diagnostic;
    // Capabilities specific to the `textDocument/documentHighlight` request.
    std::optional<DocumentHighlightClientCapabilities> document_highlight;
    // Capabilities specific to the `textDocument/documentLink` request.
    std::optional<DocumentLinkClientCapabilities> document_link;
    // Capabilities specific to the `textDocument/documentSymbol` request.
    std::optional<DocumentSymbolClientCapabilities> document_symbol;
    // Defines which filters the client supports.
    // 
    // @since 3.18.0
    std::optional<TextDocumentFilterClientCapabilities> filters;
    // Capabilities specific to the `textDocument/foldingRange` request.
    // 
    // @since 3.10.0
    std::optional<FoldingRangeClientCapabilities> folding_range;
    // Capabilities specific to the `textDocument/formatting` request.
    std::optional<DocumentFormattingClientCapabilities> formatting;
    // Capabilities specific to the `textDocument/hover` request.
    std::optional<HoverClientCapabilities> hover;
    // Capabilities specific to the `textDocument/implementation` request.
    // 
    // @since 3.6.0
    std::optional<ImplementationClientCapabilities> implementation;
    // Capabilities specific to the `textDocument/inlayHint` request.
    // 
    // @since 3.17.0
    std::optional<InlayHintClientCapabilities> inlay_hint;
    // Client capabilities specific to inline completions.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<InlineCompletionClientCapabilities> inline_completion;
    // Capabilities specific to the `textDocument/inlineValue` request.
    // 
    // @since 3.17.0
    std::optional<InlineValueClientCapabilities> inline_value;
    // Capabilities specific to the `textDocument/linkedEditingRange` request.
    // 
    // @since 3.16.0
    std::optional<LinkedEditingRangeClientCapabilities> linked_editing_range;
    // Client capabilities specific to the `textDocument/moniker` request.
    // 
    // @since 3.16.0
    std::optional<MonikerClientCapabilities> moniker;
    // Capabilities specific to the `textDocument/onTypeFormatting` request.
    std::optional<DocumentOnTypeFormattingClientCapabilities> on_type_formatting;
    // Capabilities specific to the `textDocument/publishDiagnostics` notification.
    std::optional<PublishDiagnosticsClientCapabilities> publish_diagnostics;
    // Capabilities specific to the `textDocument/rangeFormatting` request.
    std::optional<DocumentRangeFormattingClientCapabilities> range_formatting;
    // Capabilities specific to the `textDocument/references` request.
    std::optional<ReferenceClientCapabilities> references;
    // Capabilities specific to the `textDocument/rename` request.
    std::optional<RenameClientCapabilities> rename;
    // Capabilities specific to the `textDocument/selectionRange` request.
    // 
    // @since 3.15.0
    std::optional<SelectionRangeClientCapabilities> selection_range;
    // Capabilities specific to the various semantic token request.
    // 
    // @since 3.16.0
    std::optional<SemanticTokensClientCapabilities> semantic_tokens;
    // Capabilities specific to the `textDocument/signatureHelp` request.
    std::optional<SignatureHelpClientCapabilities> signature_help;
    // Defines which synchronization capabilities the client supports.
    std::optional<TextDocumentSyncClientCapabilities> synchronization;
    // Capabilities specific to the `textDocument/typeDefinition` request.
    // 
    // @since 3.6.0
    std::optional<TypeDefinitionClientCapabilities> type_definition;
    // Capabilities specific to the various type hierarchy requests.
    // 
    // @since 3.17.0
    std::optional<TypeHierarchyClientCapabilities> type_hierarchy;
};

template <>
struct glz::meta<TextDocumentClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Capabilities specific to the notebook document support.
// 
// @since 3.17.0
struct NotebookDocumentClientCapabilities
{
    // Capabilities specific to notebook document synchronization
    // 
    // @since 3.17.0
    NotebookDocumentSyncClientCapabilities synchronization;
};

template <>
struct glz::meta<NotebookDocumentClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WindowClientCapabilities
{
    // Capabilities specific to the showDocument request.
    // 
    // @since 3.16.0
    std::optional<ShowDocumentClientCapabilities> show_document;
    // Capabilities specific to the showMessage request.
    // 
    // @since 3.16.0
    std::optional<ShowMessageRequestClientCapabilities> show_message;
    // It indicates whether the client supports server initiated
    // progress using the `window/workDoneProgress/create` request.
    // 
    // The capability also controls Whether client supports handling
    // of progress notifications. If set servers are allowed to report a
    // `workDoneProgress` property in the request specific server
    // capabilities.
    // 
    // @since 3.15.0
    std::optional<bool> work_done_progress;
};

template <>
struct glz::meta<WindowClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// General client capabilities.
// 
// @since 3.16.0
struct GeneralClientCapabilities
{
    // Client capabilities specific to the client's markdown parser.
    // 
    // @since 3.16.0
    std::optional<MarkdownClientCapabilities> markdown;
    // The position encodings supported by the client. Client and server
    // have to agree on the same position encoding to ensure that offsets
    // (e.g. character position in a line) are interpreted the same on both
    // sides.
    // 
    // To keep the protocol backwards compatible the following applies: if
    // the value 'utf-16' is missing from the array of position encodings
    // servers can assume that the client supports UTF-16. UTF-16 is
    // therefore a mandatory encoding.
    // 
    // If omitted it defaults to ['utf-16'].
    // 
    // Implementation considerations: since the conversion from one encoding
    // into another requires the content of the file / line the conversion
    // is best done where the file is read which is usually on the server
    // side.
    // 
    // @since 3.17.0
    std::optional<std::vector<PositionEncodingKind>> position_encodings;
    // Client capabilities specific to regular expressions.
    // 
    // @since 3.16.0
    std::optional<RegularExpressionsClientCapabilities> regular_expressions;
    // Client capability that signals how the client
    // handles stale requests (e.g. a request
    // for which the client will not process the response
    // anymore since the information is outdated).
    // 
    // @since 3.17.0
    std::optional<StaleRequestSupportOptions> stale_request_support;
};

template <>
struct glz::meta<GeneralClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkspaceFoldersServerCapabilities
{
    // Whether the server wants to receive workspace folder
    // change notifications.
    // 
    // If a string is provided the string is treated as an ID
    // under which the notification is registered on the client
    // side. The ID can be used to unregister for these events
    // using the `client/unregisterCapability` request.
    std::optional<std::variant<std::string, bool>> change_notifications;
    // The server has support for workspace folders
    std::optional<bool> supported;
};

template <>
struct glz::meta<WorkspaceFoldersServerCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Options for notifications/requests for user operations on files.
// 
// @since 3.16.0
struct FileOperationOptions
{
    // The server is interested in receiving didCreateFiles notifications.
    std::optional<FileOperationRegistrationOptions> did_create;
    // The server is interested in receiving didDeleteFiles file notifications.
    std::optional<FileOperationRegistrationOptions> did_delete;
    // The server is interested in receiving didRenameFiles notifications.
    std::optional<FileOperationRegistrationOptions> did_rename;
    // The server is interested in receiving willCreateFiles requests.
    std::optional<FileOperationRegistrationOptions> will_create;
    // The server is interested in receiving willDeleteFiles file requests.
    std::optional<FileOperationRegistrationOptions> will_delete;
    // The server is interested in receiving willRenameFiles requests.
    std::optional<FileOperationRegistrationOptions> will_rename;
};

template <>
struct glz::meta<FileOperationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A relative pattern is a helper to construct glob patterns that are matched
// relatively to a base URI. The common value for a `baseUri` is a workspace
// folder root, but it can be another absolute URI as well.
// 
// @since 3.17.0
struct RelativePattern
{
    // A workspace folder or a base URI to which this pattern will be matched
    // against relatively.
    std::variant<WorkspaceFolder, std::string> base_uri;
    // The actual glob pattern;
    Pattern pattern;
};

template <>
struct glz::meta<RelativePattern> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A document filter where `language` is required field.
// 
// @since 3.18.0
struct TextDocumentFilterLanguage
{
    // A language id, like `typescript`.
    std::string language;
    // A glob pattern, like **​/*.{ts,js}. See TextDocumentFilter for examples.
    // 
    // @since 3.18.0 - support for relative patterns. Whether clients support
    // relative patterns depends on the client capability
    // `textDocuments.filters.relativePatternSupport`.
    std::optional<GlobPattern> pattern;
    // A Uri {@link Uri.scheme scheme}, like `file` or `untitled`.
    std::optional<std::string> scheme;
};

template <>
struct glz::meta<TextDocumentFilterLanguage> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A document filter where `scheme` is required field.
// 
// @since 3.18.0
struct TextDocumentFilterScheme
{
    // A language id, like `typescript`.
    std::optional<std::string> language;
    // A glob pattern, like **​/*.{ts,js}. See TextDocumentFilter for examples.
    // 
    // @since 3.18.0 - support for relative patterns. Whether clients support
    // relative patterns depends on the client capability
    // `textDocuments.filters.relativePatternSupport`.
    std::optional<GlobPattern> pattern;
    // A Uri {@link Uri.scheme scheme}, like `file` or `untitled`.
    std::string scheme;
};

template <>
struct glz::meta<TextDocumentFilterScheme> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A document filter where `pattern` is required field.
// 
// @since 3.18.0
struct TextDocumentFilterPattern
{
    // A language id, like `typescript`.
    std::optional<std::string> language;
    // A glob pattern, like **​/*.{ts,js}. See TextDocumentFilter for examples.
    // 
    // @since 3.18.0 - support for relative patterns. Whether clients support
    // relative patterns depends on the client capability
    // `textDocuments.filters.relativePatternSupport`.
    GlobPattern pattern;
    // A Uri {@link Uri.scheme scheme}, like `file` or `untitled`.
    std::optional<std::string> scheme;
};

template <>
struct glz::meta<TextDocumentFilterPattern> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A notebook document filter where `notebookType` is required field.
// 
// @since 3.18.0
struct NotebookDocumentFilterNotebookType
{
    // The type of the enclosing notebook.
    std::string notebook_type;
    // A glob pattern.
    std::optional<GlobPattern> pattern;
    // A Uri {@link Uri.scheme scheme}, like `file` or `untitled`.
    std::optional<std::string> scheme;
};

template <>
struct glz::meta<NotebookDocumentFilterNotebookType> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A notebook document filter where `scheme` is required field.
// 
// @since 3.18.0
struct NotebookDocumentFilterScheme
{
    // The type of the enclosing notebook.
    std::optional<std::string> notebook_type;
    // A glob pattern.
    std::optional<GlobPattern> pattern;
    // A Uri {@link Uri.scheme scheme}, like `file` or `untitled`.
    std::string scheme;
};

template <>
struct glz::meta<NotebookDocumentFilterScheme> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A notebook document filter where `pattern` is required field.
// 
// @since 3.18.0
struct NotebookDocumentFilterPattern
{
    // The type of the enclosing notebook.
    std::optional<std::string> notebook_type;
    // A glob pattern.
    GlobPattern pattern;
    // A Uri {@link Uri.scheme scheme}, like `file` or `untitled`.
    std::optional<std::string> scheme;
};

template <>
struct glz::meta<NotebookDocumentFilterPattern> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// A change describing how to move a `NotebookCell`
// array from state S to S'.
// 
// @since 3.17.0
struct NotebookCellArrayChange
{
    // The new cells, if any
    std::optional<std::vector<NotebookCell>> cells;
    // The deleted cells
    unsigned int delete_count;
    // The start oftest of the cell that changed.
    unsigned int start;
};

template <>
struct glz::meta<NotebookCellArrayChange> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct WorkspaceEditClientCapabilities
{
    // Whether the client in general supports change annotations on text edits,
    // create file, rename file and delete file changes.
    // 
    // @since 3.16.0
    std::optional<ChangeAnnotationsSupportOptions> change_annotation_support;
    // The client supports versioned document changes in `WorkspaceEdit`s
    std::optional<bool> document_changes;
    // The failure handling strategy of a client if applying the workspace edit
    // fails.
    // 
    // @since 3.13.0
    std::optional<FailureHandlingKind> failure_handling;
    // Whether the client supports `WorkspaceEditMetadata` in `WorkspaceEdit`s.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> metadata_support;
    // Whether the client normalizes line endings to the client specific
    // setting.
    // If set to `true` the client will normalize line ending characters
    // in a workspace edit to the client-specified new line
    // character.
    // 
    // @since 3.16.0
    std::optional<bool> normalizes_line_endings;
    // The resource operations the client supports. Clients should at least
    // support 'create', 'rename' and 'delete' files and folders.
    // 
    // @since 3.13.0
    std::optional<std::vector<ResourceOperationKind>> resource_operations;
    // Whether the client supports snippets as text edits.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> snippet_edit_support;
};

template <>
struct glz::meta<WorkspaceEditClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DidChangeConfigurationClientCapabilities
{
    // Did change configuration notification supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<DidChangeConfigurationClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DidChangeWatchedFilesClientCapabilities
{
    // Did change watched files notification supports dynamic registration. Please note
    // that the current protocol doesn't support static configuration for file changes
    // from the server side.
    std::optional<bool> dynamic_registration;
    // Whether the client has support for {@link  RelativePattern relative pattern}
    // or not.
    // 
    // @since 3.17.0
    std::optional<bool> relative_pattern_support;
};

template <>
struct glz::meta<DidChangeWatchedFilesClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities for a {@link WorkspaceSymbolRequest}.
struct WorkspaceSymbolClientCapabilities
{
    // Symbol request supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // The client support partial workspace symbols. The client will send the
    // request `workspaceSymbol/resolve` to the server to resolve additional
    // properties.
    // 
    // @since 3.17.0
    std::optional<ClientSymbolResolveOptions> resolve_support;
    // Specific capabilities for the `SymbolKind` in the `workspace/symbol` request.
    std::optional<ClientSymbolKindOptions> symbol_kind;
    // The client supports tags on `SymbolInformation`.
    // Clients supporting tags have to handle unknown tags gracefully.
    // 
    // @since 3.16.0
    std::optional<ClientSymbolTagOptions> tag_support;
};

template <>
struct glz::meta<WorkspaceSymbolClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The client capabilities of a {@link ExecuteCommandRequest}.
struct ExecuteCommandClientCapabilities
{
    // Execute command supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<ExecuteCommandClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensWorkspaceClientCapabilities
{
    // Whether the client implementation supports a refresh request sent from
    // the server to the client.
    // 
    // Note that this event is global and will force the client to refresh all
    // semantic tokens currently shown. It should be used with absolute care
    // and is useful for situation where a server for example detects a project
    // wide change that requires such a calculation.
    std::optional<bool> refresh_support;
};

template <>
struct glz::meta<SemanticTokensWorkspaceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct CodeLensWorkspaceClientCapabilities
{
    // Whether the client implementation supports a refresh request sent from the
    // server to the client.
    // 
    // Note that this event is global and will force the client to refresh all
    // code lenses currently shown. It should be used with absolute care and is
    // useful for situation where a server for example detect a project wide
    // change that requires such a calculation.
    std::optional<bool> refresh_support;
};

template <>
struct glz::meta<CodeLensWorkspaceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Capabilities relating to events from file operations by the user in the client.
// 
// These events do not come from the file system, they come from user operations
// like renaming a file in the UI.
// 
// @since 3.16.0
struct FileOperationClientCapabilities
{
    // The client has support for sending didCreateFiles notifications.
    std::optional<bool> did_create;
    // The client has support for sending didDeleteFiles notifications.
    std::optional<bool> did_delete;
    // The client has support for sending didRenameFiles notifications.
    std::optional<bool> did_rename;
    // Whether the client supports dynamic registration for file requests/notifications.
    std::optional<bool> dynamic_registration;
    // The client has support for sending willCreateFiles requests.
    std::optional<bool> will_create;
    // The client has support for sending willDeleteFiles requests.
    std::optional<bool> will_delete;
    // The client has support for sending willRenameFiles requests.
    std::optional<bool> will_rename;
};

template <>
struct glz::meta<FileOperationClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client workspace capabilities specific to inline values.
// 
// @since 3.17.0
struct InlineValueWorkspaceClientCapabilities
{
    // Whether the client implementation supports a refresh request sent from the
    // server to the client.
    // 
    // Note that this event is global and will force the client to refresh all
    // inline values currently shown. It should be used with absolute care and is
    // useful for situation where a server for example detects a project wide
    // change that requires such a calculation.
    std::optional<bool> refresh_support;
};

template <>
struct glz::meta<InlineValueWorkspaceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client workspace capabilities specific to inlay hints.
// 
// @since 3.17.0
struct InlayHintWorkspaceClientCapabilities
{
    // Whether the client implementation supports a refresh request sent from
    // the server to the client.
    // 
    // Note that this event is global and will force the client to refresh all
    // inlay hints currently shown. It should be used with absolute care and
    // is useful for situation where a server for example detects a project wide
    // change that requires such a calculation.
    std::optional<bool> refresh_support;
};

template <>
struct glz::meta<InlayHintWorkspaceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Workspace client capabilities specific to diagnostic pull requests.
// 
// @since 3.17.0
struct DiagnosticWorkspaceClientCapabilities
{
    // Whether the client implementation supports a refresh request sent from
    // the server to the client.
    // 
    // Note that this event is global and will force the client to refresh all
    // pulled diagnostics currently shown. It should be used with absolute care and
    // is useful for situation where a server for example detects a project wide
    // change that requires such a calculation.
    std::optional<bool> refresh_support;
};

template <>
struct glz::meta<DiagnosticWorkspaceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client workspace capabilities specific to folding ranges
// 
// @since 3.18.0
// @proposed
struct FoldingRangeWorkspaceClientCapabilities
{
    // Whether the client implementation supports a refresh request sent from the
    // server to the client.
    // 
    // Note that this event is global and will force the client to refresh all
    // folding ranges currently shown. It should be used with absolute care and is
    // useful for situation where a server for example detects a project wide
    // change that requires such a calculation.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> refresh_support;
};

template <>
struct glz::meta<FoldingRangeWorkspaceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities for a text document content provider.
// 
// @since 3.18.0
// @proposed
struct TextDocumentContentClientCapabilities
{
    // Text document content provider supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<TextDocumentContentClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct TextDocumentSyncClientCapabilities
{
    // The client supports did save notifications.
    std::optional<bool> did_save;
    // Whether text document synchronization supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // The client supports sending will save notifications.
    std::optional<bool> will_save;
    // The client supports sending a will save request and
    // waits for a response providing text edits which will
    // be applied to the document before it is saved.
    std::optional<bool> will_save_wait_until;
};

template <>
struct glz::meta<TextDocumentSyncClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct TextDocumentFilterClientCapabilities
{
    // The client supports Relative Patterns.
    // 
    // @since 3.18.0
    std::optional<bool> relative_pattern_support;
};

template <>
struct glz::meta<TextDocumentFilterClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Completion client capabilities
struct CompletionClientCapabilities
{
    // The client supports the following `CompletionItem` specific
    // capabilities.
    std::optional<ClientCompletionItemOptions> completion_item;
    std::optional<ClientCompletionItemOptionsKind> completion_item_kind;
    // The client supports the following `CompletionList` specific
    // capabilities.
    // 
    // @since 3.17.0
    std::optional<CompletionListCapabilities> completion_list;
    // The client supports to send additional context information for a
    // `textDocument/completion` request.
    std::optional<bool> context_support;
    // Whether completion supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // Defines how the client handles whitespace and indentation
    // when accepting a completion item that uses multi line
    // text in either `insertText` or `textEdit`.
    // 
    // @since 3.17.0
    std::optional<InsertTextMode> insert_text_mode;
};

template <>
struct glz::meta<CompletionClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct HoverClientCapabilities
{
    // Client supports the following content formats for the content
    // property. The order describes the preferred format of the client.
    std::optional<std::vector<MarkupKind>> content_format;
    // Whether hover supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<HoverClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client Capabilities for a {@link SignatureHelpRequest}.
struct SignatureHelpClientCapabilities
{
    // The client supports to send additional context information for a
    // `textDocument/signatureHelp` request. A client that opts into
    // contextSupport will also support the `retriggerCharacters` on
    // `SignatureHelpOptions`.
    // 
    // @since 3.15.0
    std::optional<bool> context_support;
    // Whether signature help supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // The client supports the following `SignatureInformation`
    // specific properties.
    std::optional<ClientSignatureInformationOptions> signature_information;
};

template <>
struct glz::meta<SignatureHelpClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.14.0
struct DeclarationClientCapabilities
{
    // Whether declaration supports dynamic registration. If this is set to `true`
    // the client supports the new `DeclarationRegistrationOptions` return value
    // for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
    // The client supports additional metadata in the form of declaration links.
    std::optional<bool> link_support;
};

template <>
struct glz::meta<DeclarationClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client Capabilities for a {@link DefinitionRequest}.
struct DefinitionClientCapabilities
{
    // Whether definition supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // The client supports additional metadata in the form of definition links.
    // 
    // @since 3.14.0
    std::optional<bool> link_support;
};

template <>
struct glz::meta<DefinitionClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Since 3.6.0
struct TypeDefinitionClientCapabilities
{
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `TypeDefinitionRegistrationOptions` return value
    // for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
    // The client supports additional metadata in the form of definition links.
    // 
    // Since 3.14.0
    std::optional<bool> link_support;
};

template <>
struct glz::meta<TypeDefinitionClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.6.0
struct ImplementationClientCapabilities
{
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `ImplementationRegistrationOptions` return value
    // for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
    // The client supports additional metadata in the form of definition links.
    // 
    // @since 3.14.0
    std::optional<bool> link_support;
};

template <>
struct glz::meta<ImplementationClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client Capabilities for a {@link ReferencesRequest}.
struct ReferenceClientCapabilities
{
    // Whether references supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<ReferenceClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client Capabilities for a {@link DocumentHighlightRequest}.
struct DocumentHighlightClientCapabilities
{
    // Whether document highlight supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<DocumentHighlightClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client Capabilities for a {@link DocumentSymbolRequest}.
struct DocumentSymbolClientCapabilities
{
    // Whether document symbol supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // The client supports hierarchical document symbols.
    std::optional<bool> hierarchical_document_symbol_support;
    // The client supports an additional label presented in the UI when
    // registering a document symbol provider.
    // 
    // @since 3.16.0
    std::optional<bool> label_support;
    // Specific capabilities for the `SymbolKind` in the
    // `textDocument/documentSymbol` request.
    std::optional<ClientSymbolKindOptions> symbol_kind;
    // The client supports tags on `SymbolInformation`. Tags are supported on
    // `DocumentSymbol` if `hierarchicalDocumentSymbolSupport` is set to true.
    // Clients supporting tags have to handle unknown tags gracefully.
    // 
    // @since 3.16.0
    std::optional<ClientSymbolTagOptions> tag_support;
};

template <>
struct glz::meta<DocumentSymbolClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The Client Capabilities of a {@link CodeActionRequest}.
struct CodeActionClientCapabilities
{
    // The client support code action literals of type `CodeAction` as a valid
    // response of the `textDocument/codeAction` request. If the property is not
    // set the request can only return `Command` literals.
    // 
    // @since 3.8.0
    std::optional<ClientCodeActionLiteralOptions> code_action_literal_support;
    // Whether code action supports the `data` property which is
    // preserved between a `textDocument/codeAction` and a
    // `codeAction/resolve` request.
    // 
    // @since 3.16.0
    std::optional<bool> data_support;
    // Whether code action supports the `disabled` property.
    // 
    // @since 3.16.0
    std::optional<bool> disabled_support;
    // Whether the client supports documentation for a class of
    // code actions.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> documentation_support;
    // Whether code action supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // Whether the client honors the change annotations in
    // text edits and resource operations returned via the
    // `CodeAction#edit` property by for example presenting
    // the workspace edit in the user interface and asking
    // for confirmation.
    // 
    // @since 3.16.0
    std::optional<bool> honors_change_annotations;
    // Whether code action supports the `isPreferred` property.
    // 
    // @since 3.15.0
    std::optional<bool> is_preferred_support;
    // Whether the client supports resolving additional code action
    // properties via a separate `codeAction/resolve` request.
    // 
    // @since 3.16.0
    std::optional<ClientCodeActionResolveOptions> resolve_support;
    // Client supports the tag property on a code action. Clients
    // supporting tags have to handle unknown tags gracefully.
    // 
    // @since 3.18.0 - proposed
    std::optional<CodeActionTagOptions> tag_support;
};

template <>
struct glz::meta<CodeActionClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The client capabilities  of a {@link CodeLensRequest}.
struct CodeLensClientCapabilities
{
    // Whether code lens supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // Whether the client supports resolving additional code lens
    // properties via a separate `codeLens/resolve` request.
    // 
    // @since 3.18.0
    std::optional<ClientCodeLensResolveOptions> resolve_support;
};

template <>
struct glz::meta<CodeLensClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The client capabilities of a {@link DocumentLinkRequest}.
struct DocumentLinkClientCapabilities
{
    // Whether document link supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // Whether the client supports the `tooltip` property on `DocumentLink`.
    // 
    // @since 3.15.0
    std::optional<bool> tooltip_support;
};

template <>
struct glz::meta<DocumentLinkClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct DocumentColorClientCapabilities
{
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `DocumentColorRegistrationOptions` return value
    // for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<DocumentColorClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities of a {@link DocumentFormattingRequest}.
struct DocumentFormattingClientCapabilities
{
    // Whether formatting supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<DocumentFormattingClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities of a {@link DocumentRangeFormattingRequest}.
struct DocumentRangeFormattingClientCapabilities
{
    // Whether range formatting supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // Whether the client supports formatting multiple ranges at once.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> ranges_support;
};

template <>
struct glz::meta<DocumentRangeFormattingClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities of a {@link DocumentOnTypeFormattingRequest}.
struct DocumentOnTypeFormattingClientCapabilities
{
    // Whether on type formatting supports dynamic registration.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<DocumentOnTypeFormattingClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct RenameClientCapabilities
{
    // Whether rename supports dynamic registration.
    std::optional<bool> dynamic_registration;
    // Whether the client honors the change annotations in
    // text edits and resource operations returned via the
    // rename request's workspace edit by for example presenting
    // the workspace edit in the user interface and asking
    // for confirmation.
    // 
    // @since 3.16.0
    std::optional<bool> honors_change_annotations;
    // Client supports testing for validity of rename operations
    // before execution.
    // 
    // @since 3.12.0
    std::optional<bool> prepare_support;
    // Client supports the default behavior result.
    // 
    // The value indicates the default behavior used by the
    // client.
    // 
    // @since 3.16.0
    std::optional<PrepareSupportDefaultBehavior> prepare_support_default_behavior;
};

template <>
struct glz::meta<RenameClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct FoldingRangeClientCapabilities
{
    // Whether implementation supports dynamic registration for folding range
    // providers. If this is set to `true` the client supports the new
    // `FoldingRangeRegistrationOptions` return value for the corresponding
    // server capability as well.
    std::optional<bool> dynamic_registration;
    // Specific options for the folding range.
    // 
    // @since 3.17.0
    std::optional<ClientFoldingRangeOptions> folding_range;
    // Specific options for the folding range kind.
    // 
    // @since 3.17.0
    std::optional<ClientFoldingRangeKindOptions> folding_range_kind;
    // If set, the client signals that it only supports folding complete lines.
    // If set, client will ignore specified `startCharacter` and `endCharacter`
    // properties in a FoldingRange.
    std::optional<bool> line_folding_only;
    // The maximum number of folding ranges that the client prefers to receive
    // per document. The value serves as a hint, servers are free to follow the
    // limit.
    std::optional<unsigned int> range_limit;
};

template <>
struct glz::meta<FoldingRangeClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

struct SelectionRangeClientCapabilities
{
    // Whether implementation supports dynamic registration for selection range providers. If this is set to `true`
    // the client supports the new `SelectionRangeRegistrationOptions` return value for the corresponding server
    // capability as well.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<SelectionRangeClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The publish diagnostic client capabilities.
struct PublishDiagnosticsClientCapabilities
{
    // Client supports a codeDescription property
    // 
    // @since 3.16.0
    std::optional<bool> code_description_support;
    // Whether code action supports the `data` property which is
    // preserved between a `textDocument/publishDiagnostics` and
    // `textDocument/codeAction` request.
    // 
    // @since 3.16.0
    std::optional<bool> data_support;
    // Whether the clients accepts diagnostics with related information.
    std::optional<bool> related_information;
    // Client supports the tag property to provide meta data about a diagnostic.
    // Clients supporting tags have to handle unknown tags gracefully.
    // 
    // @since 3.15.0
    std::optional<ClientDiagnosticsTagOptions> tag_support;
    // Whether the client interprets the version property of the
    // `textDocument/publishDiagnostics` notification's parameter.
    // 
    // @since 3.15.0
    std::optional<bool> version_support;
};

template <>
struct glz::meta<PublishDiagnosticsClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct CallHierarchyClientCapabilities
{
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `(TextDocumentRegistrationOptions & StaticRegistrationOptions)`
    // return value for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<CallHierarchyClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.16.0
struct SemanticTokensClientCapabilities
{
    // Whether the client uses semantic tokens to augment existing
    // syntax tokens. If set to `true` client side created syntax
    // tokens and semantic tokens are both used for colorization. If
    // set to `false` the client only uses the returned semantic tokens
    // for colorization.
    // 
    // If the value is `undefined` then the client behavior is not
    // specified.
    // 
    // @since 3.17.0
    std::optional<bool> augments_syntax_tokens;
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `(TextDocumentRegistrationOptions & StaticRegistrationOptions)`
    // return value for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
    // The token formats the clients supports.
    std::vector<TokenFormat> formats;
    // Whether the client supports tokens that can span multiple lines.
    std::optional<bool> multiline_token_support;
    // Whether the client supports tokens that can overlap each other.
    std::optional<bool> overlapping_token_support;
    // Which requests the client supports and might send to the server
    // depending on the server's capability. Please note that clients might not
    // show semantic tokens or degrade some of the user experience if a range
    // or full request is advertised by the client but not provided by the
    // server. If for example the client capability `requests.full` and
    // `request.range` are both set to true but the server only provides a
    // range provider the client might not render a minimap correctly or might
    // even decide to not show any semantic tokens at all.
    ClientSemanticTokensRequestOptions requests;
    // Whether the client allows the server to actively cancel a
    // semantic token request, e.g. supports returning
    // LSPErrorCodes.ServerCancelled. If a server does the client
    // needs to retrigger the request.
    // 
    // @since 3.17.0
    std::optional<bool> server_cancel_support;
    // The token modifiers that the client supports.
    std::vector<std::string> token_modifiers;
    // The token types that the client supports.
    std::vector<std::string> token_types;
};

template <>
struct glz::meta<SemanticTokensClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities for the linked editing range request.
// 
// @since 3.16.0
struct LinkedEditingRangeClientCapabilities
{
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `(TextDocumentRegistrationOptions & StaticRegistrationOptions)`
    // return value for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<LinkedEditingRangeClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities specific to the moniker request.
// 
// @since 3.16.0
struct MonikerClientCapabilities
{
    // Whether moniker supports dynamic registration. If this is set to `true`
    // the client supports the new `MonikerRegistrationOptions` return value
    // for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<MonikerClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.17.0
struct TypeHierarchyClientCapabilities
{
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `(TextDocumentRegistrationOptions & StaticRegistrationOptions)`
    // return value for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<TypeHierarchyClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities specific to inline values.
// 
// @since 3.17.0
struct InlineValueClientCapabilities
{
    // Whether implementation supports dynamic registration for inline value providers.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<InlineValueClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Inlay hint client capabilities.
// 
// @since 3.17.0
struct InlayHintClientCapabilities
{
    // Whether inlay hints support dynamic registration.
    std::optional<bool> dynamic_registration;
    // Indicates which properties a client can resolve lazily on an inlay
    // hint.
    std::optional<ClientInlayHintResolveOptions> resolve_support;
};

template <>
struct glz::meta<InlayHintClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities specific to diagnostic pull requests.
// 
// @since 3.17.0
struct DiagnosticClientCapabilities
{
    // Client supports a codeDescription property
    // 
    // @since 3.16.0
    std::optional<bool> code_description_support;
    // Whether code action supports the `data` property which is
    // preserved between a `textDocument/publishDiagnostics` and
    // `textDocument/codeAction` request.
    // 
    // @since 3.16.0
    std::optional<bool> data_support;
    // Whether implementation supports dynamic registration. If this is set to `true`
    // the client supports the new `(TextDocumentRegistrationOptions & StaticRegistrationOptions)`
    // return value for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
    // Whether the clients supports related documents for document diagnostic pulls.
    std::optional<bool> related_document_support;
    // Whether the clients accepts diagnostics with related information.
    std::optional<bool> related_information;
    // Client supports the tag property to provide meta data about a diagnostic.
    // Clients supporting tags have to handle unknown tags gracefully.
    // 
    // @since 3.15.0
    std::optional<ClientDiagnosticsTagOptions> tag_support;
};

template <>
struct glz::meta<DiagnosticClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities specific to inline completions.
// 
// @since 3.18.0
// @proposed
struct InlineCompletionClientCapabilities
{
    // Whether implementation supports dynamic registration for inline completion providers.
    std::optional<bool> dynamic_registration;
};

template <>
struct glz::meta<InlineCompletionClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Notebook specific client capabilities.
// 
// @since 3.17.0
struct NotebookDocumentSyncClientCapabilities
{
    // Whether implementation supports dynamic registration. If this is
    // set to `true` the client supports the new
    // `(TextDocumentRegistrationOptions & StaticRegistrationOptions)`
    // return value for the corresponding server capability as well.
    std::optional<bool> dynamic_registration;
    // The client supports sending execution summary data per cell.
    std::optional<bool> execution_summary_support;
};

template <>
struct glz::meta<NotebookDocumentSyncClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Show message request client capabilities
struct ShowMessageRequestClientCapabilities
{
    // Capabilities specific to the `MessageActionItem` type.
    std::optional<ClientShowMessageActionItemOptions> message_action_item;
};

template <>
struct glz::meta<ShowMessageRequestClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities for the showDocument request.
// 
// @since 3.16.0
struct ShowDocumentClientCapabilities
{
    // The client has support for the showDocument
    // request.
    bool support;
};

template <>
struct glz::meta<ShowDocumentClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct StaleRequestSupportOptions
{
    // The client will actively cancel the request.
    bool cancel;
    // The list of requests for which the client
    // will retry the request if it receives a
    // response with error code `ContentModified`
    std::vector<std::string> retry_on_content_modified;
};

template <>
struct glz::meta<StaleRequestSupportOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities specific to regular expressions.
// 
// @since 3.16.0
struct RegularExpressionsClientCapabilities
{
    // The engine's name.
    RegularExpressionEngineKind engine;
    // The engine's version.
    std::optional<std::string> version;
};

template <>
struct glz::meta<RegularExpressionsClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Client capabilities specific to the used markdown parser.
// 
// @since 3.16.0
struct MarkdownClientCapabilities
{
    // A list of HTML tags that the client allows / supports in
    // Markdown.
    // 
    // @since 3.17.0
    std::optional<std::vector<std::string>> allowed_tags;
    // The name of the parser.
    std::string parser;
    // The version of the parser.
    std::optional<std::string> version;
};

template <>
struct glz::meta<MarkdownClientCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ChangeAnnotationsSupportOptions
{
    // Whether the client groups edits with equal labels into tree nodes,
    // for instance all edits labelled with "Changes in Strings" would
    // be a tree node.
    std::optional<bool> groups_on_label;
};

template <>
struct glz::meta<ChangeAnnotationsSupportOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientSymbolKindOptions
{
    // The symbol kind values the client supports. When this
    // property exists the client also guarantees that it will
    // handle values outside its set gracefully and falls back
    // to a default value when unknown.
    // 
    // If this property is not present the client only supports
    // the symbol kinds from `File` to `Array` as defined in
    // the initial version of the protocol.
    std::optional<std::vector<SymbolKind>> value_set;
};

template <>
struct glz::meta<ClientSymbolKindOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientSymbolTagOptions
{
    // The tags supported by the client.
    std::vector<SymbolTag> value_set;
};

template <>
struct glz::meta<ClientSymbolTagOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientSymbolResolveOptions
{
    // The properties that a client can resolve lazily. Usually
    // `location.range`
    std::vector<std::string> properties;
};

template <>
struct glz::meta<ClientSymbolResolveOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCompletionItemOptions
{
    // Client supports commit characters on a completion item.
    std::optional<bool> commit_characters_support;
    // Client supports the deprecated property on a completion item.
    std::optional<bool> deprecated_support;
    // Client supports the following content formats for the documentation
    // property. The order describes the preferred format of the client.
    std::optional<std::vector<MarkupKind>> documentation_format;
    // Client support insert replace edit to control different behavior if a
    // completion item is inserted in the text or should replace text.
    // 
    // @since 3.16.0
    std::optional<bool> insert_replace_support;
    // The client supports the `insertTextMode` property on
    // a completion item to override the whitespace handling mode
    // as defined by the client (see `insertTextMode`).
    // 
    // @since 3.16.0
    std::optional<ClientCompletionItemInsertTextModeOptions> insert_text_mode_support;
    // The client has support for completion item label
    // details (see also `CompletionItemLabelDetails`).
    // 
    // @since 3.17.0
    std::optional<bool> label_details_support;
    // Client supports the preselect property on a completion item.
    std::optional<bool> preselect_support;
    // Indicates which properties a client can resolve lazily on a completion
    // item. Before version 3.16.0 only the predefined properties `documentation`
    // and `details` could be resolved lazily.
    // 
    // @since 3.16.0
    std::optional<ClientCompletionItemResolveOptions> resolve_support;
    // Client supports snippets as insert text.
    // 
    // A snippet can define tab stops and placeholders with `$1`, `$2`
    // and `${3:foo}`. `$0` defines the final tab stop, it defaults to
    // the end of the snippet. Placeholders with equal identifiers are linked,
    // that is typing in one will update others too.
    std::optional<bool> snippet_support;
    // Client supports the tag property on a completion item. Clients supporting
    // tags have to handle unknown tags gracefully. Clients especially need to
    // preserve unknown tags when sending a completion item back to the server in
    // a resolve call.
    // 
    // @since 3.15.0
    std::optional<CompletionItemTagOptions> tag_support;
};

template <>
struct glz::meta<ClientCompletionItemOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCompletionItemOptionsKind
{
    // The completion item kind values the client supports. When this
    // property exists the client also guarantees that it will
    // handle values outside its set gracefully and falls back
    // to a default value when unknown.
    // 
    // If this property is not present the client only supports
    // the completion items kinds from `Text` to `Reference` as defined in
    // the initial version of the protocol.
    std::optional<std::vector<CompletionItemKind>> value_set;
};

template <>
struct glz::meta<ClientCompletionItemOptionsKind> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// The client supports the following `CompletionList` specific
// capabilities.
// 
// @since 3.17.0
struct CompletionListCapabilities
{
    // Specifies whether the client supports `CompletionList.applyKind` to
    // indicate how supported values from `completionList.itemDefaults`
    // and `completion` will be combined.
    // 
    // If a client supports `applyKind` it must support it for all fields
    // that it supports that are listed in `CompletionList.applyKind`. This
    // means when clients add support for new/future fields in completion
    // items the MUST also support merge for them if those fields are
    // defined in `CompletionList.applyKind`.
    // 
    // @since 3.18.0
    std::optional<bool> apply_kind_support;
    // The client supports the following itemDefaults on
    // a completion list.
    // 
    // The value lists the supported property names of the
    // `CompletionList.itemDefaults` object. If omitted
    // no properties are supported.
    // 
    // @since 3.17.0
    std::optional<std::vector<std::string>> item_defaults;
};

template <>
struct glz::meta<CompletionListCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientSignatureInformationOptions
{
    // The client supports the `activeParameter` property on `SignatureInformation`
    // literal.
    // 
    // @since 3.16.0
    std::optional<bool> active_parameter_support;
    // Client supports the following content formats for the documentation
    // property. The order describes the preferred format of the client.
    std::optional<std::vector<MarkupKind>> documentation_format;
    // The client supports the `activeParameter` property on
    // `SignatureHelp`/`SignatureInformation` being set to `null` to
    // indicate that no parameter should be active.
    // 
    // @since 3.18.0
    // @proposed
    std::optional<bool> no_active_parameter_support;
    // Client capabilities specific to parameter information.
    std::optional<ClientSignatureParameterInformationOptions> parameter_information;
};

template <>
struct glz::meta<ClientSignatureInformationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCodeActionLiteralOptions
{
    // The code action kind is support with the following value
    // set.
    ClientCodeActionKindOptions code_action_kind;
};

template <>
struct glz::meta<ClientCodeActionLiteralOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCodeActionResolveOptions
{
    // The properties that a client can resolve lazily.
    std::vector<std::string> properties;
};

template <>
struct glz::meta<ClientCodeActionResolveOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0 - proposed
struct CodeActionTagOptions
{
    // The tags supported by the client.
    std::vector<CodeActionTag> value_set;
};

template <>
struct glz::meta<CodeActionTagOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCodeLensResolveOptions
{
    // The properties that a client can resolve lazily.
    std::vector<std::string> properties;
};

template <>
struct glz::meta<ClientCodeLensResolveOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientFoldingRangeKindOptions
{
    // The folding range kind values the client supports. When this
    // property exists the client also guarantees that it will
    // handle values outside its set gracefully and falls back
    // to a default value when unknown.
    std::optional<std::vector<FoldingRangeKind>> value_set;
};

template <>
struct glz::meta<ClientFoldingRangeKindOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientFoldingRangeOptions
{
    // If set, the client signals that it supports setting collapsedText on
    // folding ranges to display custom labels instead of the default text.
    // 
    // @since 3.17.0
    std::optional<bool> collapsed_text;
};

template <>
struct glz::meta<ClientFoldingRangeOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// General diagnostics capabilities for pull and push model.
struct DiagnosticsCapabilities
{
    // Client supports a codeDescription property
    // 
    // @since 3.16.0
    std::optional<bool> code_description_support;
    // Whether code action supports the `data` property which is
    // preserved between a `textDocument/publishDiagnostics` and
    // `textDocument/codeAction` request.
    // 
    // @since 3.16.0
    std::optional<bool> data_support;
    // Whether the clients accepts diagnostics with related information.
    std::optional<bool> related_information;
    // Client supports the tag property to provide meta data about a diagnostic.
    // Clients supporting tags have to handle unknown tags gracefully.
    // 
    // @since 3.15.0
    std::optional<ClientDiagnosticsTagOptions> tag_support;
};

template <>
struct glz::meta<DiagnosticsCapabilities> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientSemanticTokensRequestOptions
{
    // The client will send the `textDocument/semanticTokens/full` request if
    // the server provides a corresponding handler.
    std::optional<std::variant<bool, ClientSemanticTokensRequestFullDelta>> full;
    // The client will send the `textDocument/semanticTokens/range` request if
    // the server provides a corresponding handler.
    std::optional<std::variant<bool, LSPObject>> range;
};

template <>
struct glz::meta<ClientSemanticTokensRequestOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientInlayHintResolveOptions
{
    // The properties that a client can resolve lazily.
    std::vector<std::string> properties;
};

template <>
struct glz::meta<ClientInlayHintResolveOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientShowMessageActionItemOptions
{
    // Whether the client supports additional attributes which
    // are preserved and send back to the server in the
    // request's response.
    std::optional<bool> additional_properties_support;
};

template <>
struct glz::meta<ClientShowMessageActionItemOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct CompletionItemTagOptions
{
    // The tags supported by the client.
    std::vector<CompletionItemTag> value_set;
};

template <>
struct glz::meta<CompletionItemTagOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCompletionItemResolveOptions
{
    // The properties that a client can resolve lazily.
    std::vector<std::string> properties;
};

template <>
struct glz::meta<ClientCompletionItemResolveOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCompletionItemInsertTextModeOptions
{
    std::vector<InsertTextMode> value_set;
};

template <>
struct glz::meta<ClientCompletionItemInsertTextModeOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientSignatureParameterInformationOptions
{
    // The client supports processing label offsets instead of a
    // simple label string.
    // 
    // @since 3.14.0
    std::optional<bool> label_offset_support;
};

template <>
struct glz::meta<ClientSignatureParameterInformationOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientCodeActionKindOptions
{
    // The code action kind values the client supports. When this
    // property exists the client also guarantees that it will
    // handle values outside its set gracefully and falls back
    // to a default value when unknown.
    std::vector<CodeActionKind> value_set;
};

template <>
struct glz::meta<ClientCodeActionKindOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientDiagnosticsTagOptions
{
    // The tags supported by the client.
    std::vector<DiagnosticTag> value_set;
};

template <>
struct glz::meta<ClientDiagnosticsTagOptions> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// @since 3.18.0
struct ClientSemanticTokensRequestFullDelta
{
    // The client will send the `textDocument/semanticTokens/full/delta` request if
    // the server provides a corresponding handler.
    std::optional<bool> delta;
};

template <>
struct glz::meta<ClientSemanticTokensRequestFullDelta> {
    static constexpr std::string rename_key(const std::string_view key)
    {
        return to_camel_case(key);
    }
};

// Message Direction
enum class MessageDirection
{
    Both,
    ClientToServer,
    ServerToClient,
};

template <>
struct glz::meta<MessageDirection> {
    using enum MessageDirection;
    static constexpr auto value = glz::enumerate(
        "both", MessageDirection::Both,
        "clientToServer", MessageDirection::ClientToServer,
        "serverToClient", MessageDirection::ServerToClient
    );
};

// LSP Request Methods
enum class LSPRequestMethods
{
    TextDocumentImplementation,
    TextDocumentTypeDefinition,
    WorkspaceWorkspaceFolders,
    WorkspaceConfiguration,
    TextDocumentDocumentColor,
    TextDocumentColorPresentation,
    TextDocumentFoldingRange,
    WorkspaceFoldingRangeRefresh,
    TextDocumentDeclaration,
    TextDocumentSelectionRange,
    WindowWorkDoneProgressCreate,
    TextDocumentPrepareCallHierarchy,
    CallHierarchyIncomingCalls,
    CallHierarchyOutgoingCalls,
    TextDocumentSemanticTokensFull,
    TextDocumentSemanticTokensFullDelta,
    TextDocumentSemanticTokensRange,
    WorkspaceSemanticTokensRefresh,
    WindowShowDocument,
    TextDocumentLinkedEditingRange,
    WorkspaceWillCreateFiles,
    WorkspaceWillRenameFiles,
    WorkspaceWillDeleteFiles,
    TextDocumentMoniker,
    TextDocumentPrepareTypeHierarchy,
    TypeHierarchySupertypes,
    TypeHierarchySubtypes,
    TextDocumentInlineValue,
    WorkspaceInlineValueRefresh,
    TextDocumentInlayHint,
    InlayHintResolve,
    WorkspaceInlayHintRefresh,
    TextDocumentDiagnostic,
    WorkspaceDiagnostic,
    WorkspaceDiagnosticRefresh,
    TextDocumentInlineCompletion,
    WorkspaceTextDocumentContent,
    WorkspaceTextDocumentContentRefresh,
    ClientRegisterCapability,
    ClientUnregisterCapability,
    Initialize,
    Shutdown,
    WindowShowMessageRequest,
    TextDocumentWillSaveWaitUntil,
    TextDocumentCompletion,
    CompletionItemResolve,
    TextDocumentHover,
    TextDocumentSignatureHelp,
    TextDocumentDefinition,
    TextDocumentReferences,
    TextDocumentDocumentHighlight,
    TextDocumentDocumentSymbol,
    TextDocumentCodeAction,
    CodeActionResolve,
    WorkspaceSymbol,
    WorkspaceSymbolResolve,
    TextDocumentCodeLens,
    CodeLensResolve,
    WorkspaceCodeLensRefresh,
    TextDocumentDocumentLink,
    DocumentLinkResolve,
    TextDocumentFormatting,
    TextDocumentRangeFormatting,
    TextDocumentRangesFormatting,
    TextDocumentOnTypeFormatting,
    TextDocumentRename,
    TextDocumentPrepareRename,
    WorkspaceExecuteCommand,
    WorkspaceApplyEdit,
};

template <>
struct glz::meta<LSPRequestMethods> {
    using enum LSPRequestMethods;
    static constexpr auto value = glz::enumerate(
        "textDocument/implementation", LSPRequestMethods::TextDocumentImplementation,
        "textDocument/typeDefinition", LSPRequestMethods::TextDocumentTypeDefinition,
        "workspace/workspaceFolders", LSPRequestMethods::WorkspaceWorkspaceFolders,
        "workspace/configuration", LSPRequestMethods::WorkspaceConfiguration,
        "textDocument/documentColor", LSPRequestMethods::TextDocumentDocumentColor,
        "textDocument/colorPresentation", LSPRequestMethods::TextDocumentColorPresentation,
        "textDocument/foldingRange", LSPRequestMethods::TextDocumentFoldingRange,
        "workspace/foldingRange/refresh", LSPRequestMethods::WorkspaceFoldingRangeRefresh,
        "textDocument/declaration", LSPRequestMethods::TextDocumentDeclaration,
        "textDocument/selectionRange", LSPRequestMethods::TextDocumentSelectionRange,
        "window/workDoneProgress/create", LSPRequestMethods::WindowWorkDoneProgressCreate,
        "textDocument/prepareCallHierarchy", LSPRequestMethods::TextDocumentPrepareCallHierarchy,
        "callHierarchy/incomingCalls", LSPRequestMethods::CallHierarchyIncomingCalls,
        "callHierarchy/outgoingCalls", LSPRequestMethods::CallHierarchyOutgoingCalls,
        "textDocument/semanticTokens/full", LSPRequestMethods::TextDocumentSemanticTokensFull,
        "textDocument/semanticTokens/full/delta", LSPRequestMethods::TextDocumentSemanticTokensFullDelta,
        "textDocument/semanticTokens/range", LSPRequestMethods::TextDocumentSemanticTokensRange,
        "workspace/semanticTokens/refresh", LSPRequestMethods::WorkspaceSemanticTokensRefresh,
        "window/showDocument", LSPRequestMethods::WindowShowDocument,
        "textDocument/linkedEditingRange", LSPRequestMethods::TextDocumentLinkedEditingRange,
        "workspace/willCreateFiles", LSPRequestMethods::WorkspaceWillCreateFiles,
        "workspace/willRenameFiles", LSPRequestMethods::WorkspaceWillRenameFiles,
        "workspace/willDeleteFiles", LSPRequestMethods::WorkspaceWillDeleteFiles,
        "textDocument/moniker", LSPRequestMethods::TextDocumentMoniker,
        "textDocument/prepareTypeHierarchy", LSPRequestMethods::TextDocumentPrepareTypeHierarchy,
        "typeHierarchy/supertypes", LSPRequestMethods::TypeHierarchySupertypes,
        "typeHierarchy/subtypes", LSPRequestMethods::TypeHierarchySubtypes,
        "textDocument/inlineValue", LSPRequestMethods::TextDocumentInlineValue,
        "workspace/inlineValue/refresh", LSPRequestMethods::WorkspaceInlineValueRefresh,
        "textDocument/inlayHint", LSPRequestMethods::TextDocumentInlayHint,
        "inlayHint/resolve", LSPRequestMethods::InlayHintResolve,
        "workspace/inlayHint/refresh", LSPRequestMethods::WorkspaceInlayHintRefresh,
        "textDocument/diagnostic", LSPRequestMethods::TextDocumentDiagnostic,
        "workspace/diagnostic", LSPRequestMethods::WorkspaceDiagnostic,
        "workspace/diagnostic/refresh", LSPRequestMethods::WorkspaceDiagnosticRefresh,
        "textDocument/inlineCompletion", LSPRequestMethods::TextDocumentInlineCompletion,
        "workspace/textDocumentContent", LSPRequestMethods::WorkspaceTextDocumentContent,
        "workspace/textDocumentContent/refresh", LSPRequestMethods::WorkspaceTextDocumentContentRefresh,
        "client/registerCapability", LSPRequestMethods::ClientRegisterCapability,
        "client/unregisterCapability", LSPRequestMethods::ClientUnregisterCapability,
        "initialize", LSPRequestMethods::Initialize,
        "shutdown", LSPRequestMethods::Shutdown,
        "window/showMessageRequest", LSPRequestMethods::WindowShowMessageRequest,
        "textDocument/willSaveWaitUntil", LSPRequestMethods::TextDocumentWillSaveWaitUntil,
        "textDocument/completion", LSPRequestMethods::TextDocumentCompletion,
        "completionItem/resolve", LSPRequestMethods::CompletionItemResolve,
        "textDocument/hover", LSPRequestMethods::TextDocumentHover,
        "textDocument/signatureHelp", LSPRequestMethods::TextDocumentSignatureHelp,
        "textDocument/definition", LSPRequestMethods::TextDocumentDefinition,
        "textDocument/references", LSPRequestMethods::TextDocumentReferences,
        "textDocument/documentHighlight", LSPRequestMethods::TextDocumentDocumentHighlight,
        "textDocument/documentSymbol", LSPRequestMethods::TextDocumentDocumentSymbol,
        "textDocument/codeAction", LSPRequestMethods::TextDocumentCodeAction,
        "codeAction/resolve", LSPRequestMethods::CodeActionResolve,
        "workspace/symbol", LSPRequestMethods::WorkspaceSymbol,
        "workspaceSymbol/resolve", LSPRequestMethods::WorkspaceSymbolResolve,
        "textDocument/codeLens", LSPRequestMethods::TextDocumentCodeLens,
        "codeLens/resolve", LSPRequestMethods::CodeLensResolve,
        "workspace/codeLens/refresh", LSPRequestMethods::WorkspaceCodeLensRefresh,
        "textDocument/documentLink", LSPRequestMethods::TextDocumentDocumentLink,
        "documentLink/resolve", LSPRequestMethods::DocumentLinkResolve,
        "textDocument/formatting", LSPRequestMethods::TextDocumentFormatting,
        "textDocument/rangeFormatting", LSPRequestMethods::TextDocumentRangeFormatting,
        "textDocument/rangesFormatting", LSPRequestMethods::TextDocumentRangesFormatting,
        "textDocument/onTypeFormatting", LSPRequestMethods::TextDocumentOnTypeFormatting,
        "textDocument/rename", LSPRequestMethods::TextDocumentRename,
        "textDocument/prepareRename", LSPRequestMethods::TextDocumentPrepareRename,
        "workspace/executeCommand", LSPRequestMethods::WorkspaceExecuteCommand,
        "workspace/applyEdit", LSPRequestMethods::WorkspaceApplyEdit
    );
};

// LSP Notification Methods
enum class LSPNotificationMethods
{
    WorkspaceDidChangeWorkspaceFolders,
    WindowWorkDoneProgressCancel,
    WorkspaceDidCreateFiles,
    WorkspaceDidRenameFiles,
    WorkspaceDidDeleteFiles,
    NotebookDocumentDidOpen,
    NotebookDocumentDidChange,
    NotebookDocumentDidSave,
    NotebookDocumentDidClose,
    Initialized,
    Exit,
    WorkspaceDidChangeConfiguration,
    WindowShowMessage,
    WindowLogMessage,
    TelemetryEvent,
    TextDocumentDidOpen,
    TextDocumentDidChange,
    TextDocumentDidClose,
    TextDocumentDidSave,
    TextDocumentWillSave,
    WorkspaceDidChangeWatchedFiles,
    TextDocumentPublishDiagnostics,
    SetTrace,
    LogTrace,
    CancelRequest,
    Progress,
};

template <>
struct glz::meta<LSPNotificationMethods> {
    using enum LSPNotificationMethods;
    static constexpr auto value = glz::enumerate(
        "workspace/didChangeWorkspaceFolders", LSPNotificationMethods::WorkspaceDidChangeWorkspaceFolders,
        "window/workDoneProgress/cancel", LSPNotificationMethods::WindowWorkDoneProgressCancel,
        "workspace/didCreateFiles", LSPNotificationMethods::WorkspaceDidCreateFiles,
        "workspace/didRenameFiles", LSPNotificationMethods::WorkspaceDidRenameFiles,
        "workspace/didDeleteFiles", LSPNotificationMethods::WorkspaceDidDeleteFiles,
        "notebookDocument/didOpen", LSPNotificationMethods::NotebookDocumentDidOpen,
        "notebookDocument/didChange", LSPNotificationMethods::NotebookDocumentDidChange,
        "notebookDocument/didSave", LSPNotificationMethods::NotebookDocumentDidSave,
        "notebookDocument/didClose", LSPNotificationMethods::NotebookDocumentDidClose,
        "initialized", LSPNotificationMethods::Initialized,
        "exit", LSPNotificationMethods::Exit,
        "workspace/didChangeConfiguration", LSPNotificationMethods::WorkspaceDidChangeConfiguration,
        "window/showMessage", LSPNotificationMethods::WindowShowMessage,
        "window/logMessage", LSPNotificationMethods::WindowLogMessage,
        "telemetry/event", LSPNotificationMethods::TelemetryEvent,
        "textDocument/didOpen", LSPNotificationMethods::TextDocumentDidOpen,
        "textDocument/didChange", LSPNotificationMethods::TextDocumentDidChange,
        "textDocument/didClose", LSPNotificationMethods::TextDocumentDidClose,
        "textDocument/didSave", LSPNotificationMethods::TextDocumentDidSave,
        "textDocument/willSave", LSPNotificationMethods::TextDocumentWillSave,
        "workspace/didChangeWatchedFiles", LSPNotificationMethods::WorkspaceDidChangeWatchedFiles,
        "textDocument/publishDiagnostics", LSPNotificationMethods::TextDocumentPublishDiagnostics,
        "$/setTrace", LSPNotificationMethods::SetTrace,
        "$/logTrace", LSPNotificationMethods::LogTrace,
        "$/cancelRequest", LSPNotificationMethods::CancelRequest,
        "$/progress", LSPNotificationMethods::Progress
    );
};

constexpr const char* LSP_VERSION = "3.17.0";
