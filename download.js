(() => {
    if (!document.location.href.startsWith('https://leetcode.com')) {
        alert('not on https://leetcode.com');
        return;
    }

    const spans = Array.from(document.querySelectorAll('span'));
    let texts = spans.map((e) => e.innerText.trim());
    texts = texts.filter((e) => /^\d+.*[a-zA-Z].*/.test(e));

    if (texts.length === 0) {
        alert('failed to get a title');
        return;
    }

    if (texts.length > 1) {
        alert('more than two titles');
        console.log(texts);
        return;
    }

    let choice = confirm(`use title: ${texts[0]}`);
    if (choice === false) {
        console.log('user canceled.');
        return;
    }

    let divs = Array.from(document.querySelectorAll('div.view-lines'));
    const codes = divs.map((e) => e.innerText);

    if (codes.length !== 1) {
        alert('more than two codes found');
        return;
    }

    let levels = Array.from(document.querySelectorAll('div')).filter(e => ['Easy', 'Medium', 'Hard'].includes(e.innerText.trim()));
    levels = levels.map(e => e.innerText.trim());
    if (levels.size < 1) {
        alert('no level found:' + levels);
        return;
    }

    const url = document.URL;

    navigator.clipboard.writeText(
        `'${JSON.stringify({ title: texts[0], url: url, level: levels[0], code: codes[0] })}'`,
    );
})();

// how to use this?
// add to a browser bookmark: add javascrip: to address, then paste the code(not include this comments)
