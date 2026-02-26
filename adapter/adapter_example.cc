#include "adapt_legacy_rectangle.hh"
#include "legacy_rectangle.hh"

int main()
{
    LegacyRectangle adaptee = LegacyRectangle(5, 2, 8, 6);
    AdaptLegacyRectangle adapter = AdaptLegacyRectangle(adaptee);
    adapter.print();
}
