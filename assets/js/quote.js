function getQuote() {
  let quote = document.getElementById("quote");
  if (quote)
  {
    let randomQuote = beerq.BeerQuote("eng").getRandomQuote();
    quote.innerHTML = "<br><i>" + randomQuote.quote + "<br>[" + randomQuote.author + "]</i>";
  }
}

setInterval(getQuote, 10000); /*Call it here*/
getQuote();