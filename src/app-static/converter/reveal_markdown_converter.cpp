
#include <QStringList>

#include "reveal_markdown_converter.h"
#include "markdown_document.h"
#include "template/presentation_template.h"

class RevealMarkdownDocument : public MarkdownDocument
{
public:
    QString markdownText;
};

RevealMarkdownConverter::RevealMarkdownConverter()
{
}

MarkdownDocument *RevealMarkdownConverter::createDocument(const QString &text, MarkdownConverter::ConverterOptions options)
{
    Q_UNUSED(options)

    RevealMarkdownDocument *doc = new RevealMarkdownDocument();
    doc->markdownText = text;
    return doc;
}

QString RevealMarkdownConverter::renderAsHtml(MarkdownDocument *document)
{
    QString html;

    if (document) {
        RevealMarkdownDocument *doc = dynamic_cast<RevealMarkdownDocument*>(document);
        if (doc) {
            html = doc->markdownText;
        }
    }

    return html;
}

QString RevealMarkdownConverter::renderAsTableOfContents(MarkdownDocument *document)
{
    Q_UNUSED(document)

    return QString();
}

Template *RevealMarkdownConverter::templateRenderer() const
{
    static PresentationTemplate presentationTemplate;
    return &presentationTemplate;
}

MarkdownConverter::ConverterOptions RevealMarkdownConverter::supportedOptions() const
{
    return 0;
}
