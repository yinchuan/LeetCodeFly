(() => {
    if (!document.location.href.startsWith('https://leetcode.com')) {
        alert('not on https://leetcode.com');
        return;
    }

    var spans = Array.from(document.querySelectorAll('span'));
    var texts = spans.map((e) => e.innerText.trim());
    texts = texts.filter((e) => /^\d+.*[a-zA-Z].*/.test(e));

    if (texts.length === 0) {
        alert('failed to get a title');
        return;
    }

    if (texts.legnth > 1) {
        alert('more than two titles');
        console.log(texts);
        return;
    }

    let choice = confirm(`use title: ${texts[0]}`);
    if (choice === false) {
        console.log('user canceled.');
        return;
    }

    var divs = Array.from(document.querySelectorAll('div.view-lines'));
    var codes = divs.map((e) => e.innerText);

    if (codes.length !== 1) {
        alert('more than two codes found');
        return;
    }

    navigator.clipboard.writeText(
        JSON.stringify({ title: texts[0], code: codes[0] })
    );
})();

// how to use this?
// add to a browser bookmark: add javascrip: to address, then paste the code(not include this comments)
